#package Net::OAI::Record::QDC;
package QDC;

use strict;
use base qw( XML::SAX::Base );

our @QDC_ELEMENTS = qw(
    title
    alternative
    creator
    subject 
    description
    tableOfContents
    abstract
    publisher 
    contributor 
    date
    created
    valid
    available
    issued
    modified
    type
    format
    extent
    medium
    identifier
    source
    language
    relation
    isVersionOf
    hasVersion
    replaces
    isRequiredBy
    requires
    isPartOf
    hasPart
    isReferencedBy
    references
    isFormatOf
    hasFormat
    coverage
    spatial
    temporal
    rights
);

our $AUTOLOAD;

=head1 NAME

QDC - class for Qualified Dublin Core support

=head1 SYNOPSIS

=head1 DESCRIPTION

=head1 METHODS

The accessor methods are aware of their calling context (list,scalar) and
will respond appropriately. For example an item may have multiple creators,
so a call to creator() in a scalar context returns only the first creator;
and in a list context all creators are returned.

    # scalar context
    my $creator = $metadata->creator();
    
    # list context
    my @creators = $metadata->creator();

=head2 new()

=cut

sub new {
    my ( $class, %opts ) = @_;
    my $self = bless \%opts, ref( $class ) || $class;
    foreach ( @QDC_ELEMENTS ) { $self->{ $_ } = []; }
    return( $self );
}

=head2 title()

=head2 alternative()

=head2 creator()

=head2 subject ()

=head2 description()

=head2 tableOfContents()

=head2 abstract()

=head2 publisher ()

=head2 contributor ()

=head2 date()

=head2 created()

=head2 valid()

=head2 available()

=head2 issued()

=head2 modified()

=head2 type()

=head2 format()

=head2 extent()

=head2 medium()

=head2 identifier()

=head2 source()

=head2 language()

=head2 relation()

=head2 isVersionOf()

=head2 hasVersion()

=head2 replaces()

=head2 isRequiredBy()

=head2 requires()

=head2 isPartOf()

=head2 hasPart()

=head2 isReferencedBy()

=head2 references()

=head2 isFormatOf()

=head2 hasFormat()

=head2 coverage()

=head2 spatial()

=head2 temporal()

=head2 rights()


=cut

## rather than right all the accessors we use AUTOLOAD to catch calls
## valid element names as methods, and return appropriately as a list

sub AUTOLOAD {
    my $self = shift;
    my $sub = lc( $AUTOLOAD );
    $sub =~ s/.*:://;
    if ( grep /$sub/, @QDC_ELEMENTS ) {
	if ( wantarray() ) { 
	    return( @{ $self->{ $sub } } );
	} else { 
	    return( $self->{ $sub }[0] );
	}
    }
}

## generic output method 

sub asString {
    my $self = shift;
    foreach my $element ( @QDC_ELEMENTS ) {
	foreach ( @{ $self->{ $element } } ) {
	    print "$element => $_\n";
	}
    }
}

## SAX handlers

sub start_element {
    my ( $self, $element ) = @_;
    if ( $element->{ Name } eq 'metadata' ) {
	$self->{ insideMetadata } = 1;
    }
    $self->{ chars } = '';
}

sub end_element {
    my ( $self, $element ) = @_;
    ## strip namespace from element name
    my ( $elementName ) = ( $element->{ Name } =~ /^(?:.*:)?(.*)$/ );
    if ( $elementName eq 'metadata' ) { 
	$self->{ insideMetadata } = undef; 
    }
    if ( $self->{ insideMetadata } ) { 
	push( @{ $self->{ $elementName } }, $self->{ chars } );
    }
}

sub characters {
    my ( $self, $characters ) = @_;
    $self->{ chars } .= $characters->{ Data };
}

1;

