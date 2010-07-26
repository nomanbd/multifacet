##########################
# simple example of a script that
# pulls from an OAI-PMH provider,
# then inserts into a Solr index.
##########################
use Data::Dumper;
use Net::OAI::Harvester;
use WebService::Solr;

# -accept/use qualified DC
# -uses the provided QDC.pm
use QDC;

my $collections = 'Photographs of Frank R. Snyder';
my $baseURL = 'http://doyle.lib.muohio.edu/cgi-bin/oai.exe';
my $solrURL = '';

sub trim {
  my $string = shift;
  $string =~ s/^\s+//;
  $string =~ s/\s+$//;
  return $string;
}

sub build_solr_doc {

  my ($metadata, $identifier) = @_;
  my $i = 0;

  my $doc = WebService::Solr::Document->new;

  foreach my $identifier ($metadata->identifier()) {
    if ($i == 1) {
      #$doc->add_fields(url => "http://doyle.lib.muohio.edu$identifier");
      $doc->add_fields(url => $identifier);
      $doc->add_fields(url_label => "View Online");
      my @splits = split(/,/, $identifier);
      $doc->add_fields(thumbnail_image => "http://doyle.lib.muohio.edu/cgi-bin/thumbnail.exe?CISOROOT=/snyder&CISOPTR=$splits[1]");
    }
    $i++;
  }
  $i = 0;

  $doc->add_fields(source => 'mu-contentdm');
  $doc->add_fields(source_record_type => 'QDC');
  
  $identifier =~ s/\//\:/g;
  print "adding: ", $identifier, "\n";
  $doc->add_fields(id => $identifier);

  $doc->add_fields(maintitle=> $metadata->title());
  $doc->add_fields(title_proper=> $metadata->title());
  $doc->add_fields(display_title=> $metadata->title());
  
  $doc->add_fields(mainheading=> $metadata->creator());
  my $created = trim($metadata->created());
  $created =~ s/\D//g;
  $created = substr($created, 0, 4);
  print "created: ", $created, "\n";
  if ($created) {
    $doc->add_fields(original_pubdate => $created);
    $doc->add_fields(original_pubdate_start => $created);
  }

  foreach my $subject ($metadata->subject()) {
    if ($subject) {
      my @subjects = split(/;/, $subject);
      foreach my $split_subject (@subjects) {
        $split_subject = trim($split_subject);
        if ($split_subject) {
          $doc->add_fields(subjects => $split_subject);
          $doc->add_fields(topics_facet => $split_subject);
        }
      }
    }
  }

  $doc->add_fields(item_status => '-');
  $doc->add_fields(collections => $collections);

  foreach my $description ($metadata->description()) {
    if ($description) {
      $doc->add_fields(notes_public => $description);
    }
  }

  foreach my $tableOfContents ($metadata->tableOfContents()) {
    if ($tableOfContents) {
      $doc->add_fields(notes_public => $tableOfContents);
    }
  }

  foreach my $abstract ($metadata->abstract()) {
    if ($abstract) {
      $doc->add_fields(notes_public => $abstract);
    }
  }

  foreach my $publisher ($metadata->publisher()) {
    if ($publisher) {
      $doc->add_fields(publisher => $publisher);
    }
  }

  $doc->add_fields(formats => 'Electronic Resource');
  $doc->add_fields(formats => 'Photograph');
  foreach my $type ($metadata->type()) {
    if ($type) {
      my @types = split(/;/, $type);
      foreach my $split_type (@types) {
        $split_type = trim($split_type);
        if ($split_type) {
          $doc->add_fields(formats => $split_type);
        }
      }
    }
  }
  
  $doc->add_fields(bloc => 'onl');

  foreach my $format ($metadata->format()) {
    if ($format) {
      my @formats = split(/;/, $format);
      foreach my $split_format (@formats) {
        $split_format = trim($split_format);
        if ($split_format) {
          $doc->add_fields(extent => $split_format);
        }
      }
    }
  }

  foreach my $extent ($metadata->extent()) {
    if ($extent) {
      $doc->add_fields(extent => $extent);
    }
  }

  foreach my $medium ($metadata->medium()) {
    if ($medium) {
      $doc->add_fields(formats => $medium);
    }
  }

  foreach my $language ($metadata->language()) {
    if ($language) {
      $doc->add_fields(languages => $language);
    }
  }

  my $got_geographic = 0;
  my $lat;
  my $lng;
  foreach my $spatial ($metadata->spatial()) {
    if ($spatial) {
      $doc->add_fields(geographics_facet => $spatial);
    }
  }

  foreach my $temporal ($metadata->temporal()) {
    if ($temporal) {
      $doc->add_fields(original_pubdate_decades => $temporal);
    }
  }

  foreach my $rights ($metadata->rights()) {
    if ($rights) {
      $doc->add_fields(notes_public => $rights);
    }
  }

  return $doc;

}

my $harvester = Net::OAI::Harvester->new(
  baseURL => $baseURL  
);

my $records = $harvester->listAllRecords(
  metadataPrefix => 'qdc',
  metadataHandler => 'QDC',
  set => 'snyder'
);

my $solr = WebService::Solr->new($solrURL, { autocommit => 0});

while (my $record = $records->next()) {
  my $metadata = $record->metadata();
  my $header = $record->header();
  #print Dumper($metadata), "\n";
  #print Dumper($header), "\n";

  my $doc = build_solr_doc($metadata, $header->identifier());
  #print Dumper($doc), "\n";
  #print Dumper($header), "\n";
  $solr->add($doc);
}

#$solr->optimize();
