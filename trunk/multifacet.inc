<?php

/* 
 * Copyright (c) 2009 by Miami University Libraries.
 * released under the terms of the GNU Public License.
 * see the GPLv3 for details.
 *
 * Email: cassonrd@muohio.edu
 * Website: http://www.lib.muohio.edu/
 * Website: http://code.google.com/p/multifacet/
 *
 * This file is part of MULtifacet.
 * 
 * MULtifacet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * MULtifacet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with MULtifacet.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This is main configuration file
 * for MULtifacet, and as an example,
 * it has many Miami U. specific settings.
 *
 * An rudimentary (and incomplete) example
 * for a VUFind index is provided in the
 * examples/ directory.
 */

include_once("multifacet_templates.php");

global $_multifacet_solr_domain;
$_multifacet_solr_domain = "localhost";

global $_multifacet_solr_port;
$_multifacet_solr_port = "8983";

global $_multifacet_solr_base;
$_multifacet_solr_base = "solr";

/*
 * default "extras" to apply
 * to all solr searches
 *
 * might want to limit MULtifacet
 * to a specific subset of a solr
 * index by using an fq, or change
 * the facet.method, or whatever
 *
 * can certainly be multidimensional, ex:
 *
 *   $_multifacet_solr_extras = array(
 *     'facet.method' => 'fc',
 *     'indent' => 'on',
 *     'fq' => array(
 *       'formats:"Electronic Resource"',
 *     ),
 *   );
 *
 */
global $_multifacet_solr_extras;
$_multifacet_solr_extras = array(
  'facet.method' => 'fc',
  'indent' => 'on',
);

global $_multifacet_proxy_prepend;
$_multifacet_proxy_prepend = "https://proxy.lib.muohio.edu/login?url=";

global $_multifacet_tagcloud_max;
$_multifacet_tagcloud_max = 50;

global $_multifacet_tagrecent_max;
$_multifacet_tagrecent_max = 50;

global $_multifacet_tag_splitter;
$_multifacet_tag_splitter = array(
  'value' => ',',
  'label' => 'comma',
);

global $_multifacet_unique_key;
$_multifacet_unique_key = "id";

/*
 * can users send saved records
 * to an email address
 *
 * probably should be able to...
 * mainly here in case the server 
 * can't send email
 */
global $_multifacet_email_marked;
$_multifacet_email_marked = TRUE;

global $_multifacet_return_email_address;
$_multifacet_return_email_address = "DONT_REPLY@lib.muohio.edu";

global $_multifacet_ris_record_callback;
$_multifacet_ris_record_callback = '_multifacet_ris_record';

/*
 * this function must return an array, keyed
 * with title, link, and description, ie
 *
 *  $output['title'] = "blah";
 *  $output['link'] = "http://google.com";
 *  $output['description'] = "more blah";
 *  return $output;
 *
 * the actual rss items will be built
 * using drupal's format_rss_item
 */
global $_multifacet_rss_record_callback;
$_multifacet_rss_record_callback = '_multifacet_rss_record';

global $_multifacet_sms_record_callback;
$_multifacet_sms_record_callback = '_multifacet_sms_record';

global $_multifacet_brief_record_callback;
$_multifacet_brief_record_callback = '_multifacet_brief_record';

global $_multifacet_email_record_callback;
$_multifacet_email_record_callback = '_multifacet_email_record';

global $_multifacet_screen_record_callback;
$_multifacet_screen_record_callback = '_multifacet_screen_record';

global $_multifacet_full_record_callback;
$_multifacet_full_record_callback = '_multifacet_full_record';

global $_multifacet_mlt_callback;
$_multifacet_mlt_callback = '_multifacet_mlt_record';

global $_multifacet_mlt_parameters;
$_multifacet_mlt_parameters = array( 
  'mlt' => 'true',
  'mlt.fl' => 'mainheading,subjects,titles',
  'mlt.match.include' => 'false',
  'mlt.mindf' => '1',
  'mlt.mintf' => '2',
  'mlt.minwl' => '2',
  'mlt.count' => '5',
  'mlt.qf' => 'subjects^2.5 titles^1 mainheading^1.5',
);

global $_multifacet_num_search_results;
$_multifacet_num_search_results = 15;

global $_multifacet_default_search_field;
$_multifacet_default_search_field = 'keyword';

global $_multifacet_search_fields;
$_multifacet_search_fields = array(
    "keyword" => array( 
      "label" => t( "Keyword"),
      "handler" => 'dismax',
      "type" => 'dismax',
      "fields" => 'text',
    ),
    "title" => array( 
      "label" => t("Title"),
      "handler" => 'dismax',
      "type" => 'dismax',
      "fields" => 'titles',
    ),
    "author" => array( 
      "label" => t("Author"),
      "handler" => 'dismax',
      "type" => 'dismax',
      "fields" => 'authors',
    ),
    "subject" => array( 
      "label" => t("Subject"),
      "handler" => 'dismax',
      "type" => 'dismax',
      "fields" => 'subjects',
    ),
    "author_title" => array( 
      "label" => t("Author/Title"),
      "handler" => 'dismax',
      "type" => 'dismax',
      "fields" => 'authors titles',
    ),
    "callnumber" => array( 
      "label" => t( "Call Number"),
      "handler" => 'dismax',
      "type" => 'dismax',
      "fields" => 'callnumber',
    ),
    "expert" => array( 
      "label" => t( "Expert Search"),
      "handler" => 'standard',
      "type" => 'standard',
      "fields" => '',
    ),
);

global $_multifacet_default_sort_field;
$_multifacet_default_sort_field = 'score';

global $_multifacet_sort_fields;
$_multifacet_sort_fields = array(
  'score' => array(
    'label' => t('Relevance'),
    'field' => 'score desc',
  ),
  'title_asc' => array(
    'label' => t('Title A-Z'),
    'field' => 'sort_title asc',
  ),
  'title_desc' => array(
    'label' => t('Title Z-A'),
    'field' => 'sort_title desc',
  ),
  'date_desc' => array(
    'label' => t('Publication Date Desc'),
    'field' => 'original_pubdate_start desc',
  ),
  'date_asc' => array(
    'label' => t('Publication Date Asc'),
    'field' => 'original_pubdate_start asc',
  ),
  'pages_asc' => array(
    'label' => t('Page Number Asc'),
    'field' => 'pages asc',
  ),
  'pages_desc' => array(
    'label' => t('Page Number Desc'),
    'field' => 'pages desc',
  ),
);

global $_multifacet_available;
$_multifacet_available = array(
  'label' => t('Available'),
  'fq' => 'item_status:"-"',
);

/*
 * these will be used as filter queries (fq)
 * when passed to the solr index
 *
 * maybe use the forms API for this, in some
 * way?
 *
 * the key determines the form/GET variable
 * name, while the following arrays will
 * have the key, which becomes the values in
 * the html.
 *
 * when processed, the real "fq" gets pulled out 
 *
 */
global $_multifacet_advanced_limits;
$_multifacet_advanced_limits = array(
  'format' => array(
    '' => array(
      'label' => t('Any'),
    ),
    'books' => array(
      'label' => t('Books'),
      'limit' => 'composed_mattype:Books',
    ),
    'kngl' => array(
      'label' => t('King 2nd Floor'),
      'limit' => 'bloc:kngl',
    ),
    'campus' => array(
      'label' => t('Oxford Campus'),
      'limit' => 'item_campus:"Oxford"',
    ),
    'serials' => array(
      'label' => t('Serials'),
      'limit' => 'composed_mattype:Serials',
    ),
  ),
  'language' => array(
    '' => array(
      'label' => t('Any'),
    ),
    'english' => array(
      'label' => t('English'),
      'limit' => 'languages:"English"',
    ),
    'argh' => array(
      'label' => t('1990 - 1992'),
      'limit' => 'original_pubdate_start:[1990 TO 1992]',
    ),
    'argh2' => array(
      'label' => t('1990s'),
      'limit' => 'original_pubdate_start:[1990 TO 1999]',
    ),
    'spanish' => array(
      'label' => t('Spanish'),
      'limit' => 'languages:"Spanish"',
    ),
  ),
);

global $_multifacet_public_tags_default;
$_multifacet_public_tags_default = "f";

global $_multifacet_public_marked_default;
$_multifacet_public_marked_default = "f";

global $_multifacet_num_search_facets;
$_multifacet_num_search_facets = 50;

global $__multifacet_num_search_facets_shown;
$__multifacet_num_search_facets_shown = 7;

global $_multifacet_num_browse_facets;
$_multifacet_num_browse_facets = 300;

global $_multifacet_default_browse_facet;
$_multifacet_default_browse_facet = "formats";

/*
 * currently supported facet_types are
 * facet.field, or facet.prefix.
 *
 * if you choose facet.prefix, you should
 * provide an optional query to prefix on
 *
 */
global $_multifacet_tagger_facet;
$_multifacet_tagger_facet = array(
  'search_number' => $_multifacet_num_search_facets,
  'browse_number' => $_multifacet_num_browse_facets,
  'label' => t('Tagged By'),
  'facet_type' => 'facet.field',
  'facet_prefix_query' => 's',
);

global $_multifacet_tag_facet;
$_multifacet_tag_facet = array(
  'search_number' => $_multifacet_num_search_facets,
  'browse_number' => $_multifacet_num_browse_facets,
  'label' => t('Tagged'),
  'facet_type' => 'facet.field',
);

/*
 * Please, don't enable this...it
 * isn't fully complete anyway
 *
 * If you choose to set it to TRUE,
 * it won't work as you (might) expect
 *
 * You've been warned
 *
 * store tags in solr documents
 *
 * FALSE to this will disable 
 * the storing, updating, retrieval, etc
 * of tags from the solr docs.
 */
global $_multifacet_solr_tags;
$_multifacet_solr_tags = FALSE;

/*
 * fields to "unset" before adding tags/taggers
 * to a document.
 *
 * this will mainly bite you if you copyField
 * from one field to another multiValued="false"
 * field...this will throw exceptions as the original
 * value will be added, along with a new copyField-ed
 * one, per your solr schema.xml
 *
 * might consider "unsetting" all of your 
 * copyField-ed targets...
 *
 * the '$user'_tag, tag, and tagger will also be 
 * unset/reset
 */
global $_multifacet_unset_fields;
$_multifacet_unset_fields = array(
  'sort_title',
);

/*
 * for smaller indexes, you might be able 
 * to commit at the time of tagging.
 *
 * in larger ones, you'll want to commit
 * at different intervals, likely via
 * a cron job
 */
global $_multifacet_commit_on_tag;
$_multifacet_commit_on_tag = FALSE;

/*
 * currently supported facet_types are
 * facet.field, or facet.prefix.
 *
 * if you choose facet.prefix, you should
 * provide an optional query to prefix on
 *
 */
global $_multifacet_facets;
/*
$_multifacet_facets = array(
  'authors_personal' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Authors (Personal)'),
    'facet_type' => 'facet.field',
  ),
  'authors_corporate' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Authors (Corporate)'),
    'facet_type' => 'facet.field',
  ),
  'item_campus' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Campus'),
    'facet_type' => 'facet.field',
  ),
  'languages' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Language')
  ),
);
*/

$_multifacet_facets = array(
  'authors_personal' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Authors (Personal)'),
  ),
  'authors_corporate' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Authors (Corporate)'),
  ),
  'item_campus' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Campus'),
  ),
  'item_status' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Status'),
  ),
  'formats' => array( 
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Formats'),
  ),
  'original_pubdate_start' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Publication Date')
  ),
  'genres_facet' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Genre')
  ),
  'languages' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Language')
  ),
  'topics_facet' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Subject')
  ),
  'instrumentations_facet' => array( 
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Instrumentation'),
  ),
  'iloc' => array( 
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Location'),
  ),
  'coverage_dates_facet' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Coverage Date')
  ),
  'geographics_facet' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Geographic Subject')
  ),
  'collections' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Collection')
  ),
  'composed_mattype' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Material Type')
  ),
  'bloc' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Bib Location')
  ),
);

global $_multifacet_show_applied_facet;
$_multifacet_show_applied_facet = FALSE;

/*
 * NOT USED, but not deleted yet, as i may
 * change my mind....again.
 *
 * merged _search_facets with _browse_facets,
 * as i question having them separate
 *
 * which facets are returned via the browse
 *
 * can change "$num_browse_facets" for each value, 
 * if you'd prefer.
 *
 * can also reorder them.
global $multifacet_browse_facets;
$multifacet_browse_facets = array(
    "coverage_dates_facet" => array(
      'number' => 400,
      'label' => t("Coverage Date")
    ),
    "original_pubdate" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Publication Date")
    ),
    "original_pubdate_decades" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Decade Published")
    ),
    "original_pubdate_centuries" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Century Published")
    ),
    "geographics_facet" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Geographic Subject")
    ),
    "authors_personal" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Author")
    ),
    "topics_facet" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Subject")
    ),
    "formats" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Format")
    ),
    "genres_facet" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Genre")
    ),
    "composed_mattype" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Composed Material Type")
    ),
    "audience" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Audience")
    ),
    "languages" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Language")
    ),
    "biblevel" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Bibliographic Level")
    ),
    "bloc" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Bib Location")
    ),
    "iloc" => array(
      'number' => $_multifacet_num_browse_facets,
      'label' => t("Item Location")
    ),
);
 */

/*
 * full path/url to an image to show for 
 * dropping facets in the breadcrumb
 * trail
 */
global $_multifacet_drop_img;
$_multifacet_drop_img = base_path() . drupal_get_path('module', 'multifacet') 
  .'/removeIcon.gif';

/*
 * map facet values to something more human
 *
 * think about using t() for translation of these?
 *
 * you might consider converting/translating 
 * these at indextime
 */
global $_multifacet_map_facet_values;
$_multifacet_map_facet_values = array(
    "item_status" => array(
      '-' => 'AVAILABLE',
      'a' => 'ASK AT DESK',
      'b' => 'AT BINDERY',
      'c' => 'CHECK SHELVES',
      'd' => 'BURSAR',
      'e' => 'NEW BK DSPLAY',
      'f' => 'REQUEST ITEM',
      'g' => 'LIB USE ONLY',
      'h' => 'ONLINE',
      'i' => 'IN COPY CAT',
      'j' => '529-6015',
      'k' => 'TEMP UNAVAIL',
      'l' => 'IN PHYS PROC',
      'm' => 'MISSING',
      'n' => 'BILLED',
      'o' => 'LIB USE ONLY',
      'r' => 'IN REPAIR',
      't' => 'IN TRANSIT',
      'u' => 'IN REVIEW',
      'w' => 'WITHDRAWN',
      'y' => 'LOCAL CIRC',
      'z' => 'CLMS RETD',
      '$' => 'LOST; PAID',
      '!' => 'ON HOLD SHELF',
      '@' => 'OFF-CAMPUS',
      '#' => 'OHIOLINK RCVD',
      '%' => 'OHIOLINK RTN\'D',
      '&' => 'REQUESTED',
      '(' => 'OHIOLINK PAGED',
      ')' => 'CANCELLED',
      'q' => 'ASK IMC STAFF',
      '=' => 'RENEWAL DENIED',
    ),
    "doc_type" => array( 
        "opac" => "Miami U. Catalog",
        "contentdm" => "Miami U. Digital Collections",
        "ss" => "Miami U. Online Journals",
    ),
    "formats" => array( 
        "12 in. disc" => "Vinyl",
    ),
    "lang" => array( 
        "aar"  =>  "Afar",
        "abk"  =>  "Abkhaz",
        "ace"  =>  "Achinese",
        "ach"  =>  "Acoli",
        "ada"  =>  "Adangme",
        "ady"  =>  "Adygei",
        "afa"  =>  "Afroasiatic (Other)",
        "afh"  =>  "Afrihili (Artificial language)",
        "afr"  =>  "Afrikaans",
        "ajm"  =>  "Aljama",
        "aka"  =>  "Akan",
        "akk"  =>  "Akkadian",
        "alb"  =>  "Albanian",
        "ale"  =>  "Aleut",
        "alg"  =>  "Algonquian (Other)",
        "amh"  =>  "Amharic",
        "ang"  =>  "English, Old (ca. 450-1100)",
        "apa"  =>  "Apache languages",
        "ara"  =>  "Arabic",
        "arc"  =>  "Aramaic",
        "arg"  =>  "Aragonese Spanish",
        "arm"  =>  "Armenian",
        "arn"  =>  "Mapuche",
        "arp"  =>  "Arapaho",
        "art"  =>  "Artificial (Other)",
        "arw"  =>  "Arawak",
        "asm"  =>  "Assamese",
        "ast"  =>  "Bable",
        "ath"  =>  "Athapascan (Other)",
        "aus"  =>  "Australian languages",
        "ava"  =>  "Avaric",
        "ave"  =>  "Avestan",
        "awa"  =>  "Awadhi",
        "aym"  =>  "Aymara",
        "aze"  =>  "Azerbaijani",
        "bad"  =>  "Banda",
        "bai"  =>  "Bamileke languages",
        "bak"  =>  "Bashkir",
        "bal"  =>  "Baluchi",
        "bam"  =>  "Bambara",
        "ban"  =>  "Balinese",
        "baq"  =>  "Basque",
        "bas"  =>  "Basa",
        "bat"  =>  "Baltic (Other)",
        "bej"  =>  "Beja",
        "bel"  =>  "Belarusian",
        "bem"  =>  "Bemba",
        "ben"  =>  "Bengali",
        "ber"  =>  "Berber (Other)",
        "bho"  =>  "Bhojpuri",
        "bih"  =>  "Bihari",
        "bik"  =>  "Bikol",
        "bin"  =>  "Edo",
        "bis"  =>  "Bislama",
        "bla"  =>  "Siksika",
        "bnt"  =>  "Bantu (Other)",
        "bos"  =>  "Bosnian",
        "bra"  =>  "Braj",
        "bre"  =>  "Breton",
        "btk"  =>  "Batak",
        "bua"  =>  "Buriat",
        "bug"  =>  "Bugis",
        "bul"  =>  "Bulgarian",
        "bur"  =>  "Burmese",
        "cad"  =>  "Caddo",
        "cai"  =>  "Central American Indian (Other)",
        "cam"  =>  "Khmer",
        "car"  =>  "Carib",
        "cat"  =>  "Catalan",
        "cau"  =>  "Caucasian (Other)",
        "ceb"  =>  "Cebuano",
        "cel"  =>  "Celtic (Other)",
        "cha"  =>  "Chamorro",
        "chb"  =>  "Chibcha",
        "che"  =>  "Chechen",
        "chg"  =>  "Chagatai",
        "chi"  =>  "Chinese",
        "chk"  =>  "Truk",
        "chm"  =>  "Mari",
        "chn"  =>  "Chinook jargon",
        "cho"  =>  "Choctaw",
        "chp"  =>  "Chipewyan",
        "chr"  =>  "Cherokee",
        "chu"  =>  "Church Slavic",
        "chv"  =>  "Chuvash",
        "chy"  =>  "Cheyenne",
        "cmc"  =>  "Chamic languages",
        "cop"  =>  "Coptic",
        "cor"  =>  "Cornish",
        "cos"  =>  "Corsican",
        "cpe"  =>  "Creoles and Pidgins, English-based (Other)",
        "cpf"  =>  "Creoles and Pidgins, French-based (Other)",
        "cpp"  =>  "Creoles and Pidgins, Portuguese-based (Other)",
        "cre"  =>  "Cree",
        "crh"  =>  "Crimean Tatar",
        "crp"  =>  "Creoles and Pidgins (Other)",
        "cus"  =>  "Cushitic (Other)",
        "cze"  =>  "Czech",
        "dak"  =>  "Dakota",
        "dan"  =>  "Danish",
        "dar"  =>  "Dargwa",
        "day"  =>  "Dayak",
        "del"  =>  "Delaware",
        "den"  =>  "Slave",
        "dgr"  =>  "Dogrib",
        "din"  =>  "Dinka",
        "div"  =>  "Divehi",
        "doi"  =>  "Dogri",
        "dra"  =>  "Dravidian (Other)",
        "dua"  =>  "Duala",
        "dum"  =>  "Dutch, Middle (ca. 1050-1350)",
        "dut"  =>  "Dutch",
        "dyu"  =>  "Dyula",
        "dzo"  =>  "Dzongkha",
        "efi"  =>  "Efik",
        "egy"  =>  "Egyptian",
        "eka"  =>  "Ekajuk",
        "elx"  =>  "Elamite",
        "eng"  =>  "English",
        "enm"  =>  "English, Middle (1100-1500)",
        "epo"  =>  "Esperanto",
        "esk"  =>  "Eskimo languages",
        "esp"  =>  "Esperanto",
        "est"  =>  "Estonian",
        "eth"  =>  "Ethiopic",
        "ewe"  =>  "Ewe",
        "ewo"  =>  "Ewondo",
        "fan"  =>  "Fang",
        "fao"  =>  "Faroese",
        "far"  =>  "Faroese",
        "fat"  =>  "Fanti",
        "fij"  =>  "Fijian",
        "fin"  =>  "Finnish",
        "fiu"  =>  "Finno-Ugrian (Other)",
        "fon"  =>  "Fon",
        "fre"  =>  "French",
        "fri"  =>  "Frisian",
        "frm"  =>  "French, Middle (ca. 1400-1600)",
        "fro"  =>  "French, Old (ca. 842-1400)",
        "fry"  =>  "Frisian",
        "ful"  =>  "Fula",
        "fur"  =>  "Friulian",
        "gaa"  =>  "Ga",
        "gae"  =>  "Scottish Gaelic",
        "gag"  =>  "Galician",
        "gal"  =>  "Oromo",
        "gay"  =>  "Gayo",
        "gba"  =>  "Gbaya",
        "gem"  =>  "Germanic (Other)",
        "geo"  =>  "Georgian",
        "ger"  =>  "German",
        "gez"  =>  "Ethiopic",
        "gil"  =>  "Gilbertese",
        "gla"  =>  "Scottish Gaelic",
        "gle"  =>  "Irish",
        "glg"  =>  "Galician",
        "glv"  =>  "Manx",
        "gmh"  =>  "German, Middle High (ca. 1050-1500)",
        "goh"  =>  "German, Old High (ca. 750-1050)",
        "gon"  =>  "Gondi",
        "gor"  =>  "Gorontalo",
        "got"  =>  "Gothic",
        "grb"  =>  "Grebo",
        "grc"  =>  "Greek, Ancient (to 1453)",
        "gre"  =>  "Greek, Modern (1453- )",
        "grn"  =>  "Guarani",
        "gua"  =>  "Guarani",
        "guj"  =>  "Gujarati",
        "gwi"  =>  "Gwich'in",
        "hai"  =>  "Haida",
        "hat"  =>  "Haitian French Creole",
        "hau"  =>  "Hausa",
        "haw"  =>  "Hawaiian",
        "heb"  =>  "Hebrew",
        "her"  =>  "Herero",
        "hil"  =>  "Hiligaynon",
        "him"  =>  "Himachali",
        "hin"  =>  "Hindi",
        "hit"  =>  "Hittite",
        "hmn"  =>  "Hmong",
        "hmo"  =>  "Hiri Motu",
        "hun"  =>  "Hungarian",
        "hup"  =>  "Hupa",
        "iba"  =>  "Iban",
        "ibo"  =>  "Igbo",
        "ice"  =>  "Icelandic",
        "ido"  =>  "Ido",
        "iii"  =>  "Sichuan Yi",
        "ijo"  =>  "Ijo",
        "iku"  =>  "Inuktitut",
        "ile"  =>  "Interlingue",
        "ilo"  =>  "Iloko",
        "ina"  =>  "Interlingua (International Auxiliary Language",
        "inc"  =>  "Indic (Other)",
        "ind"  =>  "Indonesian",
        "ine"  =>  "Indo-European (Other)",
        "inh"  =>  "Ingush",
        "int"  =>  "Interlingua (International Auxiliary Language",
        "ipk"  =>  "Inupiaq",
        "ira"  =>  "Iranian (Other)",
        "iri"  =>  "Irish",
        "iro"  =>  "Iroquoian (Other)",
        "ita"  =>  "Italian",
        "jav"  =>  "Javanese",
        "jpn"  =>  "Japanese",
        "jpr"  =>  "Judeo-Persian",
        "jrb"  =>  "Judeo-Arabic",
        "kaa"  =>  "Kara-Kalpak",
        "kab"  =>  "Kabyle",
        "kac"  =>  "Kachin",
        "kal"  =>  "Kalatdlisut",
        "kam"  =>  "Kamba",
        "kan"  =>  "Kannada",
        "kar"  =>  "Karen",
        "kas"  =>  "Kashmiri",
        "kau"  =>  "Kanuri",
        "kaw"  =>  "Kawi",
        "kaz"  =>  "Kazakh",
        "kbd"  =>  "Kabardian",
        "kha"  =>  "Khasi",
        "khi"  =>  "Khoisan (Other)",
        "khm"  =>  "Khmer",
        "kho"  =>  "Khotanese",
        "kik"  =>  "Kikuyu",
        "kin"  =>  "Kinyarwanda",
        "kir"  =>  "Kyrgyz",
        "kmb"  =>  "Kimbundu",
        "kok"  =>  "Konkani",
        "kom"  =>  "Komi",
        "kon"  =>  "Kongo",
        "kor"  =>  "Korean",
        "kos"  =>  "Kusaie",
        "kpe"  =>  "Kpelle",
        "kro"  =>  "Kru",
        "kru"  =>  "Kurukh",
        "kua"  =>  "Kuanyama",
        "kum"  =>  "Kumyk",
        "kur"  =>  "Kurdish",
        "kus"  =>  "Kusaie",
        "kut"  =>  "Kutenai",
        "lad"  =>  "Ladino",
        "lah"  =>  "Lahnda",
        "lam"  =>  "Lamba",
        "lan"  =>  "Occitan (post-1500)",
        "lao"  =>  "Lao",
        "lap"  =>  "Sami",
        "lat"  =>  "Latin",
        "lav"  =>  "Latvian",
        "lez"  =>  "Lezgian",
        "lim"  =>  "Limburgish",
        "lin"  =>  "Lingala",
        "lit"  =>  "Lithuanian",
        "lol"  =>  "Mongo-Nkundu",
        "loz"  =>  "Lozi",
        "ltz"  =>  "Letzeburgesch",
        "lua"  =>  "Luba-Lulua",
        "lub"  =>  "Luba-Katanga",
        "lug"  =>  "Ganda",
        "lui"  =>  "Luiseno",
        "lun"  =>  "Lunda",
        "luo"  =>  "Luo (Kenya and Tanzania)",
        "lus"  =>  "Lushai",
        "mac"  =>  "Macedonian",
        "mad"  =>  "Madurese",
        "mag"  =>  "Magahi",
        "mah"  =>  "Marshallese",
        "mai"  =>  "Maithili",
        "mak"  =>  "Makasar",
        "mal"  =>  "Malayalam",
        "man"  =>  "Mandarin",
        "mao"  =>  "Maori",
        "map"  =>  "Austronesian (Other)",
        "mar"  =>  "Marathi",
        "mas"  =>  "Masai",
        "max"  =>  "Manx",
        "may"  =>  "Malay",
        "mdr"  =>  "Mandar",
        "men"  =>  "Mende",
        "mga"  =>  "Irish, Middle (ca. 1100-1550)",
        "mic"  =>  "Micmac",
        "min"  =>  "Minangkabau",
        "mis"  =>  "Miscellaneous languages",
        "mkh"  =>  "Mon-Khmer (Other)",
        "mla"  =>  "Malagasy",
        "mlg"  =>  "Malagasy",
        "mlt"  =>  "Maltese",
        "mnc"  =>  "Manchu",
        "mni"  =>  "Manipuri",
        "mno"  =>  "Manobo languages",
        "moh"  =>  "Mohawk",
        "mol"  =>  "Moldavian",
        "mon"  =>  "Mongolian",
        "mos"  =>  "Moore",
        "mul"  =>  "Multiple languages",
        "mun"  =>  "Munda (Other)",
        "mus"  =>  "Creek",
        "mwr"  =>  "Marwari",
        "myn"  =>  "Mayan languages",
        "nah"  =>  "Nahuatl",
        "nai"  =>  "North American Indian (Other)",
        "nap"  =>  "Neapolitan Italian",
        "nau"  =>  "Nauru",
        "nav"  =>  "Navajo",
        "nbl"  =>  "Ndebele (South Africa)",
        "nde"  =>  "Ndebele (Zimbabwe)",
        "ndo"  =>  "Ndonga",
        "nds"  =>  "Low German",
        "nep"  =>  "Nepali",
        "new"  =>  "Newari",
        "nia"  =>  "Nias",
        "nic"  =>  "Niger-Kordofanian (Other)",
        "niu"  =>  "Niuean",
        "nno"  =>  "Norwegian (Nynorsk)",
        "nob"  =>  "Norwegian (Bokmal)",
        "nog"  =>  "Nogai",
        "non"  =>  "Old Norse",
        "nor"  =>  "Norwegian",
        "nso"  =>  "Northern Sotho",
        "nub"  =>  "Nubian languages",
        "nya"  =>  "Nyanja",
        "nym"  =>  "Nyamwezi",
        "nyn"  =>  "Nyankole",
        "nyo"  =>  "Nyoro",
        "nzi"  =>  "Nzima",
        "oci"  =>  "Occitan (post-1500)",
        "oji"  =>  "Ojibwa",
        "ori"  =>  "Oriya",
        "orm"  =>  "Oromo",
        "osa"  =>  "Osage",
        "oss"  =>  "Ossetic",
        "ota"  =>  "Turkish, Ottoman",
        "oto"  =>  "Otomian languages",
        "paa"  =>  "Papuan (Other)",
        "pag"  =>  "Pangasinan",
        "pal"  =>  "Pahlavi",
        "pam"  =>  "Pampanga",
        "pan"  =>  "Panjabi",
        "pap"  =>  "Papiamento",
        "pau"  =>  "Palauan",
        "peo"  =>  "Old Persian (ca. 600-400 B.C.)",
        "per"  =>  "Persian",
        "phi"  =>  "Philippine (Other)",
        "phn"  =>  "Phoenician",
        "pli"  =>  "Pali",
        "pol"  =>  "Polish",
        "pon"  =>  "Ponape",
        "por"  =>  "Portuguese",
        "pra"  =>  "Prakrit languages",
        "pro"  =>  "Provencal (to 1500)",
        "pus"  =>  "Pushto",
        "que"  =>  "Quechua",
        "raj"  =>  "Rajasthani",
        "rap"  =>  "Rapanui",
        "rar"  =>  "Rarotongan",
        "roa"  =>  "Romance (Other)",
        "roh"  =>  "Raeto-Romance",
        "rom"  =>  "Romani",
        "rum"  =>  "Romanian",
        "run"  =>  "Rundi",
        "rus"  =>  "Russian",
        "sad"  =>  "Sandawe",
        "sag"  =>  "Sango (Ubangi Creole)",
        "sah"  =>  "Yakut",
        "sai"  =>  "South American Indian (Other)",
        "sal"  =>  "Salishan languages",
        "sam"  =>  "Samaritan Aramaic",
        "san"  =>  "Sanskrit",
        "sao"  =>  "Samoan",
        "sas"  =>  "Sasak",
        "sat"  =>  "Santali",
        "scc"  =>  "Serbian",
        "sco"  =>  "Scots",
        "scr"  =>  "Croatian",
        "sel"  =>  "Selkup",
        "sem"  =>  "Semitic (Other)",
        "sga"  =>  "Irish, Old (to 1100)",
        "sgn"  =>  "Sign languages",
        "shn"  =>  "Shan",
        "sho"  =>  "Shona",
        "sid"  =>  "Sidamo",
        "sin"  =>  "Sinhalese",
        "sio"  =>  "Siouan (Other)",
        "sit"  =>  "Sino-Tibetan (Other)",
        "sla"  =>  "Slavic (Other)",
        "slo"  =>  "Slovak",
        "slv"  =>  "Slovenian",
        "sma"  =>  "Southern Sami",
        "sme"  =>  "Northern Sami",
        "smi"  =>  "Sami",
        "smj"  =>  "Lule Sami",
        "smn"  =>  "Inari Sami",
        "smo"  =>  "Samoan",
        "sms"  =>  "Skolt Sami",
        "sna"  =>  "Shona",
        "snd"  =>  "Sindhi",
        "snh"  =>  "Sinhalese",
        "snk"  =>  "Soninke",
        "sog"  =>  "Sogdian",
        "som"  =>  "Somali",
        "son"  =>  "Songhai",
        "sot"  =>  "Sotho",
        "spa"  =>  "Spanish",
        "srd"  =>  "Sardinian",
        "srr"  =>  "Serer",
        "ssa"  =>  "Nilo-Saharan (Other)",
        "sso"  =>  "Sotho",
        "ssw"  =>  "Swazi",
        "suk"  =>  "Sukuma",
        "sun"  =>  "Sundanese",
        "sus"  =>  "Susu",
        "sux"  =>  "Sumerian",
        "swa"  =>  "Swahili",
        "swe"  =>  "Swedish",
        "swz"  =>  "Swazi",
        "syr"  =>  "Syriac",
        "tag"  =>  "Tagalog",
        "tah"  =>  "Tahitian",
        "tai"  =>  "Tai (Other)",
        "taj"  =>  "Tajik",
        "tam"  =>  "Tamil",
        "tar"  =>  "Tatar",
        "tat"  =>  "Tatar",
        "tel"  =>  "Telugu",
        "tem"  =>  "Temne",
        "ter"  =>  "Terena",
        "tet"  =>  "Tetum",
        "tgk"  =>  "Tajik",
        "tgl"  =>  "Tagalog",
        "tha"  =>  "Thai",
        "tib"  =>  "Tibetan",
        "tig"  =>  "Tigre",
        "tir"  =>  "Tigrinya",
        "tiv"  =>  "Tiv",
        "tkl"  =>  "Tokelauan",
        "tli"  =>  "Tlingit",
        "tmh"  =>  "Tamashek",
        "tog"  =>  "Tonga (Nyasa)",
        "ton"  =>  "Tongan",
        "tpi"  =>  "Tok Pisin",
        "tru"  =>  "Truk",
        "tsi"  =>  "Tsimshian",
        "tsn"  =>  "Tswana",
        "tso"  =>  "Tsonga",
        "tsw"  =>  "Tswana",
        "tuk"  =>  "Turkmen",
        "tum"  =>  "Tumbuka",
        "tup"  =>  "Tupi languages",
        "tur"  =>  "Turkish",
        "tut"  =>  "Altaic (Other)",
        "tvl"  =>  "Tuvaluan",
        "twi"  =>  "Twi",
        "tyv"  =>  "Tuvinian",
        "udm"  =>  "Udmurt",
        "uga"  =>  "Ugaritic",
        "uig"  =>  "Uighur",
        "ukr"  =>  "Ukrainian",
        "umb"  =>  "Umbundu",
        "und"  =>  "Undetermined",
        "urd"  =>  "Urdu",
        "uzb"  =>  "Uzbek",
        "vai"  =>  "Vai",
        "ven"  =>  "Venda",
        "vie"  =>  "Vietnamese",
        "vol"  =>  "Volapuk",
        "vot"  =>  "Votic",
        "wak"  =>  "Wakashan languages",
        "wal"  =>  "Walamo",
        "war"  =>  "Waray",
        "was"  =>  "Washo",
        "wel"  =>  "Welsh",
        "wen"  =>  "Sorbian languages",
        "wln"  =>  "Walloon",
        "wol"  =>  "Wolof",
        "xal"  =>  "Kalmyk",
        "xho"  =>  "Xhosa",
        "yao"  =>  "Yao (Africa)",
        "yap"  =>  "Yapese",
        "yid"  =>  "Yiddish",
        "yor"  =>  "Yoruba",
        "ypk"  =>  "Yupik languages",
        "zap"  =>  "Zapotec",
        "zen"  =>  "Zenaga",
        "zha"  =>  "Zhuang",
        "znd"  =>  "Zande",
        "zul"  =>  "Zulu",
        "zun"  =>  "Zuni",
        "zxx"  =>  "zxx",
    ),
    "bloc" => array( 
      "mu3ug	aal"   => "ArtArch",
      "mu3ug	doc"   => "King - Gov & Law",
      "mu3ug	ext"   => "Other Campus Collections ",
      "mu3ug	gask"   => "Other Campus Collections ",
      "mu3ug	hal"   => "Hamilton Reserve",
      "mu3ug	imc"   => "IMC",
      "mu3ug	kngl"   => "King",
      "mu3ug	mdl"   => "Middletown Reserve",
      "mu3ug	mul"   => "Music",
      "mu3ug	murc"   => "Music Listening Center",
      "mu3ug	onl"   => "Online",
      "mu3ug	onl"   => "Online",
      "mu3ug	scl"   => "Science",
      "mu3ug	spe"   => "Special Collections",
      "mu3ug	swdep"   => "SW Regional Depository",
    ),
    "iloc" => array(
        "mu3ug	aac"   =>  "ArtArch Circ",
        "mu3ug	aacls"   =>  "ArtArch Closed Stacks",
        "mu3ug	aaff"   =>  "ArtArch Oversize",
        "mu3ug	aafo"   =>  "ArtArch Folio",
        "mu3ug	aali"   => "ArtArch",
        "mu3ug	aap"   =>  "ArtArch Per",
        "mu3ug	aar"   =>  "ArtArch Ref",
        "mu3ug	aarm"   =>  "ArtArch CD-ROM",
        "mu3ug	aars"   =>  "ArtArch Reserve",
        "mu3ug	aast"   =>  "ArtArch",
        "mu3ug	aavc"   =>  "ArtArch VideoC",
        "mu3ug	acq"   =>  "King Acquisitions Dept.",
        "mu3ug	arcli"   =>  "Archives",
        "mu3ug	cat"   =>  "Cat",
        "mu3ug	cbcli"   =>  "CBCL 17B Warfield Hall",
        "mu3ug	ccat"   =>  "Copy Cataloging",
        "mu3ug	cdlan"   =>  "CD-ROM LAN",
        "mu3ug	cect"   =>  "CETC Library",
        "mu3ug	cetc"   =>  "CETC Library",
        "mu3ug	cppli"   =>  "CPPO Library",
        "mu3ug	docc"   =>  "Gov Census",
        "mu3ug	doceu"   =>  "GovEuro",
        "mu3ug	docfc"   =>  "Gov Mfiche",
        "mu3ug	docfm"   =>  "Gov Mfilm",
        "mu3ug	docl"   =>  "Gov & Law",
        "mu3ug	docli"   =>  "Gov & Law",
        "mu3ug	doclo"   =>  "Internet Resource",
        "mu3ug	doco"   =>  "Gov & Law Ohio",
        "mu3ug	docr"   =>  "Gov  Ref",
        "mu3ug	docrm"   =>  "Gov CD-ROM",
        "mu3ug	docrs"   =>  "Gov   Res",
        "mu3ug	docsf"   =>  "Gov USMicro",
        "mu3ug	docsr"   =>  "Gov USRef",
        "mu3ug	docun"   =>  "GovUN",
        "mu3ug	film"   =>  "MCIS Media Dist",
        "mu3ug	glba"   =>  "Spectrum Office",
        "mu3ug	haat"   =>  "Hamilton Atlas Case",
        "mu3ug	hach"   =>  "Hamilton Library",
        "mu3ug	hafc"   =>  "Hamilton Microfiche",
        "mu3ug	hafmp"   =>  "Hamilton Microfilm Per",
        "mu3ug	hali"   =>  "Hamilton Library",
        "mu3ug	halst"   =>  "Hamilton Storage",
        "mu3ug	hamc"   =>  "Hamilton McNaughton",
        "mu3ug	hanb"   =>  "Hamilton Nonbook",
        "mu3ug	hanmd"   =>  "140 University Hall (Ham.)",
        "mu3ug	har"   =>  "Hamilton Reference",
        "mu3ug	hars"   =>  "Hamilton Reserve",
        "mu3ug	hrbli"   =>  "Herbarium - Upham",
        "mu3ug	imbk"   =>  "IMC  Book",
        "mu3ug	imbkt"   =>  "IMC Textbook",
        "mu3ug	imci"   =>  "IMC  Circ",
        "mu3ug	imcra"   =>  "IMC MCard",
        "mu3ug	imcrc"   =>  "IMC MCard",
        "mu3ug	imcrp"   =>  "IMC MCard Per",
        "mu3ug	imcur"   =>  "IMC CurrMat",
        "mu3ug	imdvd"   =>  "IMC   DVD",
        "mu3ug	imfca"   =>  "IMC Mfiche",
        "mu3ug	imfcc"   =>  "IMC Mfiche",
        "mu3ug	imfcn"   =>  "IMC Mfiche NewP",
        "mu3ug	imfcp"   =>  "IMC Mfiche Per",
        "mu3ug	imfma"   =>  "IMC Mfilm",
        "mu3ug	imfmc"   =>  "IMC Mfilm",
        "mu3ug	imfmn"   =>  "Microform Storage - IMC Microfilm Newspaper",
        "mu3ug	imfmp"   =>  "IMC Mfilm NewsP",
        "mu3ug	imfs"   =>  "IMC  Films",
        "mu3ug	imjb"   =>  "Juv BigBook",
        "mu3ug	imje"   =>  "Juv  Easy",
        "mu3ug	imju"   =>  "Juv",
        "mu3ug	imlng"   =>  "Juv LangMat",
        "mu3ug	imm"   =>  "IMC CurrMat",
        "mu3ug	imp"   =>  "IMC  Per",
        "mu3ug	impra"   =>  "IMC Mprint",
        "mu3ug	imprc"   =>  "IMC Mprint",
        "mu3ug	imr"   =>  "IMC Ref",
        "mu3ug	imrdr"   =>  "IMC Readers",
        "mu3ug	imrs"   =>  "IMC Reserve ",
        "mu3ug	imtst"   =>  "IMC Test",
        "mu3ug	imvc"   =>  "IMC VideoC",
        "mu3ug	imvcs"   =>  "Alumni IMC Storage",
        "mu3ug	imvd"   =>  "IMC VideoD",
        "mu3ug	imvr"   =>  "IMC Video Clsd",
        "mu3ug	kng3"   =>  "King Library First Floor",
        "mu3ug	kngc"   =>  "King Circ",
        "mu3ug	kngcm"   =>  "King  CIM",
        "mu3ug	kngfc"   =>  "King Mfiche",
        "mu3ug	kngfm"   =>  "King Mfilm",
        "mu3ug	kngfo"   =>  "King Folio",
        "mu3ug	kngin"   =>  "King Index",
        "mu3ug	kngle"   =>  "King Leisure, 2nd Floor",
        "mu3ug	kngli"   =>  "King Library Second Floor",
        "mu3ug	kngln"   =>  "now in King",
        "mu3ug	kngp"   =>  "King Per",
        "mu3ug	kngr"   =>  "King  Ref",
        "mu3ug	kngrm"   =>  "King CD-ROM",
        "mu3ug	kngrr"   =>  "King ReadyRef",
        "mu3ug	kngrs"   =>  "King Reserve",
        "mu3ug	mda"   =>  "Middletown Archives",
        "mu3ug	mddo"   =>  "Middletown Ohio Doc",
        "mu3ug	mdfo"   =>  "Middletown Folio",
        "mu3ug	mdim"   =>  "Middletown IMC",
        "mu3ug	mdju"   =>  "Middletown Juvenile",
        "mu3ug	mdli"   =>  "Middletown Campus",
        "mu3ug	mdmc"   =>  "Middletown McNaughton",
        "mu3ug	mdnmd"   =>  "101 Thesken (Mid.)",
        "mu3ug	mdr"   =>  "Middletown Reference",
        "mu3ug	mdrc"   =>  "Middletown Recordings",
        "mu3ug	mdrs"   =>  "Middletown Reserve",
        "mu3ug	mdtr"   =>  "Middletown Teaching RC",
        "mu3ug	muc"   =>  "Music Circ",
        "mu3ug	mudc"   =>  "Music",
        "mu3ug	mufc"   =>  "Music Mfiche",
        "mu3ug	mufm"   =>  "Music Mfilm",
        "mu3ug	mufo"   =>  "Music Folio",
        "mu3ug	muli"   =>  "Amos Music Library",
        "mu3ug	mup"   =>  "Music Per",
        "mu3ug	mur"   =>  "Music Ref",
        "mu3ug	murc"   =>  "Music",
        "mu3ug	murcd"   =>  "Music Listening Center",
        "mu3ug	murcr"   =>  "Music Listening Center Reserve",
        "mu3ug	murcv"   =>  "Music Listening Center",
        "mu3ug	murs"   =>  "Music Reserve",
        "mu3ug	onl$"   =>  "Internet Resource",
        "mu3ug	onl@"   =>  "Internet Resource",
        "mu3ug	onli"   =>  "Internet Resource",
        "mu3ug	onlm"   =>  "Internet Resource",
        "mu3ug	onlo"   =>  "Internet Resource",
        "mu3ug	onlp"   =>  "Internet Resource",
        "mu3ug	onlt"   =>  "Online",
        "mu3ug	onlw"   =>  "Internet Resource",
        "mu3ug	rg2pa"   =>  "SW Depository",
        "mu3ug	rg2pc"   =>  "SW Depository",
        "mu3ug	rg2pd"   =>  "SW Depository",
        "mu3ug	rg2ph"   =>  "SW Depository",
        "mu3ug	rg2pk"   =>  "SW Depository",
        "mu3ug	rg2pm"   =>  "SW Depository",
        "mu3ug	rg2ps"   =>  "SW Depository",
        "mu3ug	rg2ta"   =>  "SW Depository",
        "mu3ug	rg2tc"   =>  "SW Depository",
        "mu3ug	rg2td"   =>  "SW Depository",
        "mu3ug	rg2tf"   =>  "SW Depository",
        "mu3ug	rg2tg"   =>  "SW Depository",
        "mu3ug	rg2th"   =>  "SW Depository",
        "mu3ug	rg2ti"   =>  "SW Depository",
        "mu3ug	rg2tk"   =>  "SW Depository",
        "mu3ug	rg2tl"   =>  "SW Depository",
        "mu3ug	rg2tm"   =>  "SW Depository",
        "mu3ug	rg2tr"   =>  "SW Depository",
        "mu3ug	rg2ts"   =>  "SW Depository",
        "mu3ug	rgspa"   =>  "SW Depository",
        "mu3ug	rgspc"   =>  "SW Depository",
        "mu3ug	rgspd"   =>  "SW Depository",
        "mu3ug	rgsph"   =>  "SW Depository",
        "mu3ug	rgspk"   =>  "SW Depository",
        "mu3ug	rgspm"   =>  "SW Depository",
        "mu3ug	rgsps"   =>  "SW Depository",
        "mu3ug	rgsta"   =>  "SW Depository",
        "mu3ug	rgstc"   =>  "SW Depository",
        "mu3ug	rgstd"   =>  "SW Depository",
        "mu3ug	rgstg"   =>  "SW Depository",
        "mu3ug	rgsth"   =>  "SW Depository",
        "mu3ug	rgsti"   =>  "SW Depository",
        "mu3ug	rgstk"   =>  "SW Depository",
        "mu3ug	rgstm"   =>  "SW Depository",
        "mu3ug	rgstr"   =>  "SW Depository",
        "mu3ug	rgsts"   =>  "SW Depository",
        "mu3ug	scat"   =>  "Sci Atlas",
        "mu3ug	scc"   =>  "Sci  Circ",
        "mu3ug	sccra"   =>  "Sci MCard",
        "mu3ug	sccrc"   =>  "Sci Mcard",
        "mu3ug	sccrp"   =>  "Sci Mcard Per",
        "mu3ug	scfca"   =>  "Sci Mfiche",
        "mu3ug	scfcc"   =>  "Sci Mfiche",
        "mu3ug	scfcp"   =>  "Microform Storage Sci Microfiche Per",
        "mu3ug	scfma"   =>  "Sci Mfilm",
        "mu3ug	scfmc"   =>  "Sci Mfilm",
        "mu3ug	scfmp"   =>  "Microform Storage Sci Microfilm Per",
        "mu3ug	scfo"   =>  "Science Folio",
        "mu3ug	scin"   =>  "Sci Index",
        "mu3ug	sckuc"   =>  "Sci Kuchler",
        "mu3ug	sckur"   =>  "Science Kuchler Room",
        "mu3ug	scli"   =>  "Science Library 3rd Floor",
        "mu3ug	sclit"   =>  "Science Thesis",
        "mu3ug	scmp"   =>  "Sci   Map",
        "mu3ug	scmpc"   =>  "SciMapCb",
        "mu3ug	scmph"   =>  "SciMapHz",
        "mu3ug	scmpv"   =>  "SciMapVt",
        "mu3ug	scp"   =>  "Science Periodical",
        "mu3ug	scr"   =>  "Sci   Ref",
        "mu3ug	scrm"   =>  "Sci CD-ROM",
        "mu3ug	scrr"   =>  "Sci ReadyRef",
        "mu3ug	scrs"   =>  "Sci Reserve",
        "mu3ug	scst"   =>  "Sci Storage",
        "mu3ug	scstf"   =>  "Sci Folio",
        "mu3ug	sloli"   =>  "Student Lead. Off.",
        "mu3ug	spcfo"   =>  "Spec Folio",
        "mu3ug	spe18"   =>  "Spec1841",
        "mu3ug	spec"   =>  "Special Collections",
        "mu3ug	specd"   =>  "Spec Dewey",
        "mu3ug	speck"   =>  "SpecKing",
        "mu3ug	speco"   =>  "Cov",
        "mu3ug	specp"   =>  "Spec Per",
        "mu3ug	specs"   =>  "Spec SchoolBk",
        "mu3ug	specv"   =>  "Spec Coll Closed Stks",
        "mu3ug	spedf"   =>  "Spec Defoe Collection",
        "mu3ug	spefc"   =>  "Spec Mfiche",
        "mu3ug	spefm"   =>  "Spec Mfilm",
        "mu3ug	spegr"   =>  "Spec Goldau Collection",
        "mu3ug	spemg"   =>  "Spec McGuffey Coll",
        "mu3ug	spemy"   =>  "Myaamia",
        "mu3ug	spevf"   =>  "Spec Coll Closed Stks folio",
        "mu3ug	spkfo"   =>  "SpecKing Folio",
        "mu3ug	spmss"   =>  "SpecMSS",
        "mu3ug	wesar"   =>  "Peabody Western Archives",
        "mu3ug	wocli"   =>  "Womens Center",
    ),
);

global $_multifacet_worldcat_apikey;
$_multifacet_worldcat_apikey = "5IURDHOjh3k0nVXhCpOIltZrc3jjPkihk0byqILeRGYyRzuo8PxVPpqkGSDJFzM4Q8D5IiXL41aU4iT3";

/*
 * worldcat currently accepts apa, chicago,
 * harvard, mla, turabian, or all
 */
global $_multifacet_worldcat_citation_format;
$_multifacet_worldcat_citation_format = 'all';

/*
 * enable refworks export
 */
global $_multifacet_do_refworks;
$_multifacet_do_refworks = TRUE;

/*
 * here for convenience. probably
 * doesn't need changing
 */
global $_multifacet_refworks_prepend;
$_multifacet_refworks_prepend = "http://www.refworks.com/express/ExpressImport.asp?vendor=MiamiU&filter=RIS%20Format&database=MULtifacet&encoding=65001";

/*
 * do google books lookup/replacement
 */
global $_multifacet_do_gbooks;
$_multifacet_do_gbooks = TRUE;

/*
 * borrowing heavily from Art Zemon's ltcovers.php caching
 *
 *  http://cheerfulcurmudgeon.com/2008/08/11/caching-free-librarything-book-covers/
 *
 */
// librarything api key
global $_multifacet_librarything_apikey;
$_multifacet_librarything_apikey = "9dd36c125936b0178879faaf7d8cad4f";

// a default image to show 
global $_multifacet_librarything_default_image;
$_multifacet_librarything_default_image = "/home/rcasson/drupal/modules/multifacet/transparent.gif";

// a directory to cache images in 
global $_multifacet_librarything_cache_dir;
$_multifacet_librarything_cache_dir = "/var/tmp";

/*
 * sms carriers for texting bibrecords
 */
global $_multifacet_sms_carriers;
$_multifacet_sms_carriers = array(
  "localhost" => "Localhost Testing",
  "gocbw.com" => "Cincinnati Bell",
  "txt.att.net" => "Cingular/AT&T",
  "tmomail.net" => "T-Mobile",
  "vtext.com" => "Verizon",
  "messaging.sprintpcs.com" => "Sprint",
  "messaging.nextel.com" => "Nextel",
  "email.uscc.net" => "US Cellular",
);

global $_multifacet_unapi_formats;
$_multifacet_unapi_formats = array(
  "ris" => array( 
    "content-type" => "text/plain",
    "docs" => "http://www.adeptscience.co.uk/kb/article/A626",
    "source" => "multifacet",
    "callback" => $_multifacet_ris_record_callback,
  ),
);

/*
 * an optional url to a 'help'
 * page.
 *
 * probably best to provide an
 * absolute url.
 */
global $_multifacet_help_url;
$_multifacet_help_url = "";
