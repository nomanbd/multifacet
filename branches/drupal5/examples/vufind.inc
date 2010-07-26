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
include_once("multifacet_templates.php");

global $_multifacet_solr_domain;
$_multifacet_solr_domain = "localhost";

global $_multifacet_solr_port;
$_multifacet_solr_port = "8080";

global $_multifacet_solr_base;
$_multifacet_solr_base = "solr/biblio";

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
$_multifacet_brief_record_callback = '_multifacet_brief_record_vufind';

global $_multifacet_email_record_callback;
$_multifacet_email_record_callback = '_multifacet_email_record';

global $_multifacet_screen_record_callback;
$_multifacet_screen_record_callback = '_multifacet_screen_record';

global $_multifacet_full_record_callback;
$_multifacet_full_record_callback = '_multifacet_full_record_vufind';

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
    'keyword' => array( 
      'label' => t( 'Keyword'),
      'handler' => 'standard',
      'type' => 'standard',
      'fields' => 'allfields',
    ),
    'title' => array( 
      'label' => t('Title'),
      'handler' => 'standard',
      'type' => 'standard',
      'fields' => 'title',
    ),
    'author' => array( 
      'label' => t('Author'),
      'handler' => 'standard',
      'type' => 'standard',
      'fields' => 'author',
    ),
    'expert' => array( 
      'label' => t( 'Expert Search'),
      'handler' => 'standard',
      'type' => 'standard',
      'fields' => '',
    ),
);

global $_multifacet_default_sort_field;
$_multifacet_default_sort_field = 'score';

/*
 * leave empty if you don't want any
 * sort options shown to users
 */
global $_multifacet_sort_fields;
$_multifacet_sort_fields = array(
  'score' => array(
    'label' => t('Relevance'),
    'field' => 'score desc',
  ),
  'title_asc' => array(
    'label' => t('Title A-Z'),
    'field' => 'titleStr asc',
  ),
  'title_desc' => array(
    'label' => t('Title Z-A'),
    'field' => 'titleStr desc',
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

/*
 * leave empty if you are not
 * pre-indexing 'availability'
 */
global $_multifacet_available;
$_multifacet_available = array(
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
  'authorStr' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Authors (Personal)'),
    'facet_type' => 'facet.field',
  ),
);
*/

$_multifacet_facets = array(
  'auth_authorStr' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Author'),
  ),
  'language' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Language'),
  ),
  'genreStr' => array(
    'search_number' => $_multifacet_num_search_facets,
    'browse_number' => $_multifacet_num_browse_facets,
    'label' => t('Genre'),
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
        "aal"   => "ArtArch",
        "doc"   => "King - Gov & Law",
        "ext"   => "Other Campus Collections ",
        "gask"   => "Other Campus Collections ",
        "hal"   => "Hamilton Reserve",
        "imc"   => "IMC",
        "kngl"   => "King",
        "mdl"   => "Middletown Reserve",
        "mul"   => "Music",
        "murc"   => "Music Listening Center",
        "onl"   => "Online",
        "onl"   => "Online",
        "scl"   => "Science",
        "spe"   => "Special Collections",
        "swdep"   => "SW Regional Depository",
    ),
    "iloc" => array(
        "aac"   =>  "ArtArch Circ",
        "aacls"   =>  "ArtArch Closed Stacks",
        "aaff"   =>  "ArtArch Oversize",
        "aafo"   =>  "ArtArch Folio",
        "aali"   => "ArtArch",
        "aap"   =>  "ArtArch Per",
        "aar"   =>  "ArtArch Ref",
        "aarm"   =>  "ArtArch CD-ROM",
        "aars"   =>  "ArtArch Reserve",
        "aast"   =>  "ArtArch",
        "aavc"   =>  "ArtArch VideoC",
        "acq"   =>  "King Acquisitions Dept.",
        "arcli"   =>  "Archives",
        "cat"   =>  "Cat",
        "cbcli"   =>  "CBCL 17B Warfield Hall",
        "ccat"   =>  "Copy Cataloging",
        "cdlan"   =>  "CD-ROM LAN",
        "cect"   =>  "CETC Library",
        "cetc"   =>  "CETC Library",
        "cppli"   =>  "CPPO Library",
        "docc"   =>  "Gov Census",
        "doceu"   =>  "GovEuro",
        "docfc"   =>  "Gov Mfiche",
        "docfm"   =>  "Gov Mfilm",
        "docl"   =>  "Gov & Law",
        "docli"   =>  "Gov & Law",
        "doclo"   =>  "Internet Resource",
        "doco"   =>  "Gov & Law Ohio",
        "docr"   =>  "Gov  Ref",
        "docrm"   =>  "Gov CD-ROM",
        "docrs"   =>  "Gov   Res",
        "docsf"   =>  "Gov USMicro",
        "docsr"   =>  "Gov USRef",
        "docun"   =>  "GovUN",
        "film"   =>  "MCIS Media Dist",
        "glba"   =>  "Spectrum Office",
        "haat"   =>  "Hamilton Atlas Case",
        "hach"   =>  "Hamilton Library",
        "hafc"   =>  "Hamilton Microfiche",
        "hafmp"   =>  "Hamilton Microfilm Per",
        "hali"   =>  "Hamilton Library",
        "halst"   =>  "Hamilton Storage",
        "hamc"   =>  "Hamilton McNaughton",
        "hanb"   =>  "Hamilton Nonbook",
        "hanmd"   =>  "140 University Hall (Ham.)",
        "har"   =>  "Hamilton Reference",
        "hars"   =>  "Hamilton Reserve",
        "hrbli"   =>  "Herbarium - Upham",
        "imbk"   =>  "IMC  Book",
        "imbkt"   =>  "IMC Textbook",
        "imci"   =>  "IMC  Circ",
        "imcra"   =>  "IMC MCard",
        "imcrc"   =>  "IMC MCard",
        "imcrp"   =>  "IMC MCard Per",
        "imcur"   =>  "IMC CurrMat",
        "imdvd"   =>  "IMC   DVD",
        "imfca"   =>  "IMC Mfiche",
        "imfcc"   =>  "IMC Mfiche",
        "imfcn"   =>  "IMC Mfiche NewP",
        "imfcp"   =>  "IMC Mfiche Per",
        "imfma"   =>  "IMC Mfilm",
        "imfmc"   =>  "IMC Mfilm",
        "imfmn"   =>  "Microform Storage - IMC Microfilm Newspaper",
        "imfmp"   =>  "IMC Mfilm NewsP",
        "imfs"   =>  "IMC  Films",
        "imjb"   =>  "Juv BigBook",
        "imje"   =>  "Juv  Easy",
        "imju"   =>  "Juv",
        "imlng"   =>  "Juv LangMat",
        "imm"   =>  "IMC CurrMat",
        "imp"   =>  "IMC  Per",
        "impra"   =>  "IMC Mprint",
        "imprc"   =>  "IMC Mprint",
        "imr"   =>  "IMC Ref",
        "imrdr"   =>  "IMC Readers",
        "imrs"   =>  "IMC Reserve ",
        "imtst"   =>  "IMC Test",
        "imvc"   =>  "IMC VideoC",
        "imvcs"   =>  "Alumni IMC Storage",
        "imvd"   =>  "IMC VideoD",
        "imvr"   =>  "IMC Video Clsd",
        "kng3"   =>  "King Library First Floor",
        "kngc"   =>  "King Circ",
        "kngcm"   =>  "King  CIM",
        "kngfc"   =>  "King Mfiche",
        "kngfm"   =>  "King Mfilm",
        "kngfo"   =>  "King Folio",
        "kngin"   =>  "King Index",
        "kngle"   =>  "King Leisure, 2nd Floor",
        "kngli"   =>  "King Library Second Floor",
        "kngln"   =>  "now in King",
        "kngp"   =>  "King Per",
        "kngr"   =>  "King  Ref",
        "kngrm"   =>  "King CD-ROM",
        "kngrr"   =>  "King ReadyRef",
        "kngrs"   =>  "King Reserve",
        "mda"   =>  "Middletown Archives",
        "mddo"   =>  "Middletown Ohio Doc",
        "mdfo"   =>  "Middletown Folio",
        "mdim"   =>  "Middletown IMC",
        "mdju"   =>  "Middletown Juvenile",
        "mdli"   =>  "Middletown Campus",
        "mdmc"   =>  "Middletown McNaughton",
        "mdnmd"   =>  "101 Thesken (Mid.)",
        "mdr"   =>  "Middletown Reference",
        "mdrc"   =>  "Middletown Recordings",
        "mdrs"   =>  "Middletown Reserve",
        "mdtr"   =>  "Middletown Teaching RC",
        "muc"   =>  "Music Circ",
        "mudc"   =>  "Music",
        "mufc"   =>  "Music Mfiche",
        "mufm"   =>  "Music Mfilm",
        "mufo"   =>  "Music Folio",
        "muli"   =>  "Amos Music Library",
        "mup"   =>  "Music Per",
        "mur"   =>  "Music Ref",
        "murc"   =>  "Music",
        "murcd"   =>  "Music Listening Center",
        "murcr"   =>  "Music Listening Center Reserve",
        "murcv"   =>  "Music Listening Center",
        "murs"   =>  "Music Reserve",
        "onl$"   =>  "Internet Resource",
        "onl@"   =>  "Internet Resource",
        "onli"   =>  "Internet Resource",
        "onlm"   =>  "Internet Resource",
        "onlo"   =>  "Internet Resource",
        "onlp"   =>  "Internet Resource",
        "onlt"   =>  "Online",
        "onlw"   =>  "Internet Resource",
        "rg2pa"   =>  "SW Depository",
        "rg2pc"   =>  "SW Depository",
        "rg2pd"   =>  "SW Depository",
        "rg2ph"   =>  "SW Depository",
        "rg2pk"   =>  "SW Depository",
        "rg2pm"   =>  "SW Depository",
        "rg2ps"   =>  "SW Depository",
        "rg2ta"   =>  "SW Depository",
        "rg2tc"   =>  "SW Depository",
        "rg2td"   =>  "SW Depository",
        "rg2tf"   =>  "SW Depository",
        "rg2tg"   =>  "SW Depository",
        "rg2th"   =>  "SW Depository",
        "rg2ti"   =>  "SW Depository",
        "rg2tk"   =>  "SW Depository",
        "rg2tl"   =>  "SW Depository",
        "rg2tm"   =>  "SW Depository",
        "rg2tr"   =>  "SW Depository",
        "rg2ts"   =>  "SW Depository",
        "rgspa"   =>  "SW Depository",
        "rgspc"   =>  "SW Depository",
        "rgspd"   =>  "SW Depository",
        "rgsph"   =>  "SW Depository",
        "rgspk"   =>  "SW Depository",
        "rgspm"   =>  "SW Depository",
        "rgsps"   =>  "SW Depository",
        "rgsta"   =>  "SW Depository",
        "rgstc"   =>  "SW Depository",
        "rgstd"   =>  "SW Depository",
        "rgstg"   =>  "SW Depository",
        "rgsth"   =>  "SW Depository",
        "rgsti"   =>  "SW Depository",
        "rgstk"   =>  "SW Depository",
        "rgstm"   =>  "SW Depository",
        "rgstr"   =>  "SW Depository",
        "rgsts"   =>  "SW Depository",
        "scat"   =>  "Sci Atlas",
        "scc"   =>  "Sci  Circ",
        "sccra"   =>  "Sci MCard",
        "sccrc"   =>  "Sci Mcard",
        "sccrp"   =>  "Sci Mcard Per",
        "scfca"   =>  "Sci Mfiche",
        "scfcc"   =>  "Sci Mfiche",
        "scfcp"   =>  "Microform Storage Sci Microfiche Per",
        "scfma"   =>  "Sci Mfilm",
        "scfmc"   =>  "Sci Mfilm",
        "scfmp"   =>  "Microform Storage Sci Microfilm Per",
        "scfo"   =>  "Science Folio",
        "scin"   =>  "Sci Index",
        "sckuc"   =>  "Sci Kuchler",
        "sckur"   =>  "Science Kuchler Room",
        "scli"   =>  "Science Library 3rd Floor",
        "sclit"   =>  "Science Thesis",
        "scmp"   =>  "Sci   Map",
        "scmpc"   =>  "SciMapCb",
        "scmph"   =>  "SciMapHz",
        "scmpv"   =>  "SciMapVt",
        "scp"   =>  "Science Periodical",
        "scr"   =>  "Sci   Ref",
        "scrm"   =>  "Sci CD-ROM",
        "scrr"   =>  "Sci ReadyRef",
        "scrs"   =>  "Sci Reserve",
        "scst"   =>  "Sci Storage",
        "scstf"   =>  "Sci Folio",
        "sloli"   =>  "Student Lead. Off.",
        "spcfo"   =>  "Spec Folio",
        "spe18"   =>  "Spec1841",
        "spec"   =>  "Special Collections",
        "specd"   =>  "Spec Dewey",
        "speck"   =>  "SpecKing",
        "speco"   =>  "Cov",
        "specp"   =>  "Spec Per",
        "specs"   =>  "Spec SchoolBk",
        "specv"   =>  "Spec Coll Closed Stks",
        "spedf"   =>  "Spec Defoe Collection",
        "spefc"   =>  "Spec Mfiche",
        "spefm"   =>  "Spec Mfilm",
        "spegr"   =>  "Spec Goldau Collection",
        "spemg"   =>  "Spec McGuffey Coll",
        "spemy"   =>  "Myaamia",
        "spevf"   =>  "Spec Coll Closed Stks folio",
        "spkfo"   =>  "SpecKing Folio",
        "spmss"   =>  "SpecMSS",
        "wesar"   =>  "Peabody Western Archives",
        "wocli"   =>  "Womens Center",
    ),
);

global $_multifacet_worldcat_apikey;
$_multifacet_worldcat_apikey = "";

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
$_multifacet_librarything_apikey = "";

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
