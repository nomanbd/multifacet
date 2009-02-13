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
 * very, very basic set of templates
 * for putting on top of an existing
 * vufind index.
 *
 * these are simply examples, and probably
 * don't work very well....just included
 * to get the ball rolling.
 *
 * if you get a good set of templates,
 * please let me know, and they can replace
 * these :)
 */
function _multifacet_brief_record_vufind ($doc) {

  global $_multifacet_tag_splitter, $_multifacet_unique_key, $user;

  $output .= '<div id="multifacet_brief_' . $doc->$_multifacet_unique_key . '">';
 
  $doc->id = preg_replace('/^ocm/', '', $doc->id);
  $doc->id = preg_replace('/^ocn/', '', $doc->id);
  
  $output .= '<div class="right_brief">';
  
  $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 0);

  if ( $doc->id) {
    $output .= multifacet_gbooks_template("OCLC:" . $doc->id);
  } elseif ($doc->isn) {
    $output .= multifacet_gbooks_template("ISBN:" . $doc->isn[0]);
  }

  /*
  $output .= '<div class="right_brief" style="float: right;">';
  if ((string)strpos($_GET['q'], "multifacet/marked") == "0") {
    $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 1);
  } else {
    $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 0);
  }
  */

  //$output .= multifacet_coins_template( $doc);

  $output .= "</div>";

  $output .= '<div class="left_brief">';
  $output .= '<a name="' . $doc->$_multifacet_unique_key . '" href="' 
    . base_path() . 'multifacet/record/' 
    . $doc->$_multifacet_unique_key . '">' . $doc->titleStr . '</a>';
  
  $output .= " (" . _multifacet_to_iii( $doc->$_multifacet_unique_key) . ")";
  
  if ( count($doc->author)) {
    $output .= '<div><strong>' . t("Main Author:") . '</strong> ';
    $output .= '<a href="' . base_path() . 'search/multifacet/' . 
      drupal_urlencode('"' . $doc->author . '"') .  '&amp;field=author">' . 
      check_plain($doc->author) . '</a><?div>';
  }
  
  if ( count($doc->building)) {

    for ( $i = 0; $i < count( $doc->building); $i++) {

      $output .= '<div class="item_location"><strong>' . t('Location: ')
        . '</strong>' . _multifacet_map_facet_values('building', $doc->building[$i]) 
        . ': ' . $doc->callnumber;
      
      if ( isset($doc->item_volume[$i])) {
        $output .= ' ' . $doc->item_volume[$i];
      }

      if ( isset($doc->item_copy[$i])) {
        $output .= ' c. ' . $doc->item_copy[$i];
      }

      $output .= ' ' . _multifacet_map_facet_values('item_status',
        $doc->item_status[$i]);
      
      $output .= '</div>';

    }
  
  }

  if ( count( $doc->format)) {
    $output .= '<div><strong>' . t( 'Format: ') . '</strong>';
    $output .= implode(", ", $doc->format);
    $output .= '</div>';
  }

  if ($doc->composed_mattype) {
    $output .= '<div><strong>' . t( 'Material Type: ') . '</strong>';
    $output .= $doc->composed_mattype;
    $output .= '</div>';
  }
  
  if ($doc->pages) {
    $output .= '<div><strong>' . t( 'Number of Pages: ') . '</strong>';
    $output .= $doc->pages;
    $output .= '</div>';
  }

  //$output .= multifacet_worldcat_template($doc->id);

  $output .= multifacet_cite_template($doc->id);

  $output .= multifacet_sms_template( $doc->$_multifacet_unique_key);
 
  $output .= multifacet_tag_template($doc->$_multifacet_unique_key);

  $output .= multifacet_refworks_template($doc->$_multifacet_unique_key);
 
  $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 0);

  $output .= multifacet_delicious_template( $doc);

  $output .= multifacet_coins_template( $doc);
 
  $output .= multifacet_unapi_template($doc->$_multifacet_unique_key);

  $output .= "</div>";

  $output .= '</div>';

  return $output;

}


function _multifacet_brief_record_local ($doc) {

  global $_multifacet_tag_splitter, $_multifacet_unique_key, $user;

  $output .= '<div id="multifacet_brief_' . $doc->$_multifacet_unique_key . '">';
 
  $doc->id = preg_replace('/^ocm/', '', $doc->id);
  $doc->id = preg_replace('/^ocn/', '', $doc->id);
  
  $output .= '<div class="right_brief">';
  
  $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 0);

  if ( $doc->id) {
    $output .= multifacet_gbooks_template("OCLC:" . $doc->id);
  } elseif ($doc->isn) {
    $output .= multifacet_gbooks_template("ISBN:" . $doc->isn[0]);
  }

  /*
  $output .= '<div class="right_brief" style="float: right;">';
  if ((string)strpos($_GET['q'], "multifacet/marked") == "0") {
    $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 1);
  } else {
    $output .= multifacet_mark_template($doc->$_multifacet_unique_key, 0);
  }
  */

  //$output .= multifacet_coins_template( $doc);

  $output .= "</div>";

  $output .= '<div class="left_brief">';
  $output .= '<a name="' . $doc->$_multifacet_unique_key . '" href="' 
    . base_path() . 'multifacet/record/' 
    . $doc->$_multifacet_unique_key . '">' . $doc->display_title . '</a>';
  
  $output .= " (" . _multifacet_to_iii( $doc->$_multifacet_unique_key) . ")";
  
  if ( count($doc->mainheading)) {
    $i = 0;
    foreach ( $doc->mainheading as $mainheading) {
      if ( $i) {
        $output .= ", ";
      } else {
        $output .= '<br />' . t(" by ");
      }
      $output .= '<a href="' . base_path() . 'search/multifacet/' . 
        drupal_urlencode('"' . $mainheading . '"') .  '&amp;field=author">' . 
        check_plain($mainheading) . '</a>';
      $i++;
    }
  }

  if ( count($doc->iloc)) {

    for ( $i = 0; $i < count( $doc->iloc); $i++) {

      $output .= '<div class="item_location"><strong>' . t('Location: ')
        . '</strong>' . _multifacet_map_facet_values('iloc', $doc->iloc[$i]) 
        . ': ' . $doc->item_callnumber[$i];
      
      if ( isset($doc->item_volume[$i])) {
        $output .= ' ' . $doc->item_volume[$i];
      }

      if ( isset($doc->item_copy[$i])) {
        $output .= ' c. ' . $doc->item_copy[$i];
      }

      $output .= ' ' . _multifacet_map_facet_values('item_status',
        $doc->item_status[$i]);
      
      $output .= '</div>';

    }
  
  }

  if ( count( $doc->formats)) {
    $output .= '<div><strong>' . t( 'Format: ') . '</strong>';
    $output .= implode(", ", $doc->formats);
    $output .= '</div>';
  }

  if ($doc->composed_mattype) {
    $output .= '<div><strong>' . t( 'Material Type: ') . '</strong>';
    $output .= $doc->composed_mattype;
    $output .= '</div>';
  }
  
  if ($doc->pages) {
    $output .= '<div><strong>' . t( 'Number of Pages: ') . '</strong>';
    $output .= $doc->pages;
    $output .= '</div>';
  }

  //$output .= multifacet_worldcat_template($doc->id);

  $output .= multifacet_cite_template($doc->id);

  $output .= multifacet_tag_template($doc->$_multifacet_unique_key);

  $output .= multifacet_sms_template( $doc->$_multifacet_unique_key);
  
  $output .= " (" . _multifacet_to_iii( $doc->$_multifacet_unique_key) . ")";
  
  $output .= multifacet_refworks_template($doc->$_multifacet_unique_key);
  
  $output .= multifacet_delicious_template( $doc);

  $output .= multifacet_coins_template( $doc);

  $output .= "</div>";

  $output .= '</div>';

  return $output;

}

function _multifacet_to_iii ($id) {

  $output .= '<a target="_blank" class="external" 
    href="http://holmes.lib.muohio.edu/record=' 
    . drupal_urlencode(substr($id, 5)) . '">' . t('Classic View') . '</a>';

  return $output;

}

function _multifacet_full_record_vufind ($doc) {

  global $_multifacet_do_gbooks;

  $js = "var Drupal_base_path = '" . base_path() . "';";
  drupal_add_js($js, 'inline');
  drupal_add_js(drupal_get_path('module', 'multifacet') . 
    '/jquery.multifacet.js');
  drupal_add_css(drupal_get_path('module', 'multifacet') . '/multifacet.css');
  drupal_set_title( $doc->titleStr);

  //$output .= $doc->display_title;
 
  $output .= '<div>';
  if ( $_multifacet_do_gbooks)  {

    $output .= '
    <script type="text/javascript">
    $(document).ready(function(){
      var gbooks = $("a.multifacet_gbook");
      var gbooks_query = "";
      if (gbooks.length) {

        for ( var i = 0; i < gbooks.length; i++) {
          if ( gbooks_query) {
            gbooks_query += ",";
          }
          gbooks_query += gbooks[i].id;
        }
        
        $("body").append("<script type=\'text/javascript\' src=\'http://books.google.com/books?jscmd=viewapi&bibkeys=" + gbooks_query + "&callback=ProcessGBSBookInfo\'><\/script>");
      }
    });
    </script>
    ';
  
  }

  $output .= '<div style="float: right; clear: right; margin: 10px;">';
  if (isset($doc->id)) {
    $doc->id = preg_replace('/\s/', '', $doc->id);
    $doc->id = preg_replace('/^ocm/', '', $doc->id);
    $doc->id = preg_replace('/^ocn/', '', $doc->id);
    $output .= multifacet_gbooks_template("OCLC:" . $doc->id);
  } elseif (isset($doc->isn)) {
    $output .= multifacet_gbooks_template("ISBN:" . $doc->isn[0]);
  } elseif (isset($doc->national_control_number)) {
    $output .= multifacet_gbooks_template("LCCN:" . 
      $doc->national_control_number[0]);
  }
  $output .= '</div>';

  $output .= '<table class="multifacet_record_details">';

  if ( isset( $doc->mainheading)) {
      $output .= '<tr><th>' . t( "Main Author: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->mainheading as $mainheading) {
        if ( $i) {
          $output .= "<br />";
        }
        $output .= '<a href="' . base_path() . 'search/multifacet/' . 
          drupal_urlencode('"' . $mainheading . '"') .  '&amp;field=author">' . 
          check_plain($mainheading) . '</a>';
        $i++;
      }
      $output .= '</td></tr>';
  }

  // don't show if authors is exact same as mainheading
  if ( isset( $doc->authors) && $doc->authors != $doc->mainheading) {
      $output .= '<tr><th>' . t( "Other Authors: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->authors as $author) {
        // hide any that are already show as mainheadings
        if (!@in_array($author, $doc->mainheading))  {
          if ( $i) {
            $output .= ", ";
          }
          $output .= '<a href="' . base_path() . 'search/multifacet/' . 
            drupal_urlencode('"' . $author . '"') .  '&amp;field=author">' . 
            check_plain($author) . '</a>';
          $i++;
        }
      }
      $output .= '</td></tr>';
  }

  if ( isset( $doc->formats)) {
      $output .= '<tr><th>' 
        . t( "Formats: ") . '</th><td>';
      $i = 0;
      foreach ( $doc->formats as $format) {
        if ( $i) {
          $output .= ", ";
        }
        $output .= _multifacet_map_facet_values('formats', 
          check_plain($format));
        $i++;
      }
      $output .= '</td></tr>';
  }

  if ( isset( $doc->composed_mattype)) {
      $output .= '<tr><th>' 
        . t( "Material Type: ") . '</th><td>' 
        . _multifacet_map_facet_values('composed_mattype', 
          check_plain($doc->composed_mattype)) . '</td></tr>';
  }

  if ( isset( $doc->languages)) {
      $output .= '<tr><th>' . t( "Language: ")
        . '</th><td>' . check_plain(implode(", ", $doc->languages)) 
        . '</td></tr>';
  }

  if ( isset( $doc->imprint)) {
    $output .= '<tr><th>' . t("Published: ") 
      . '</th><td>' . check_plain(implode( '<br />', $doc->imprint)) 
      . '</td></tr>';
  }
  
  if ( isset( $doc->series_traced)) {
      $output .= '<tr><th>' . t( "Series: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->series_traced as $series) {
        if ( $i) {
          $output .= "<br />";
        }
        $series_info = explode("\t", $series);
        $output .= '<a href="' . base_path() . 'search/multifacet/' . 
          drupal_urlencode($series_info[0]) .  '&amp;field=keyword">' . 
          check_plain($series_info[0]) . '</a>';
        $i++;
      }
      $output .= '</td></tr>';
  }

  if ( isset( $doc->subjects)) {
      $output .= '<tr><th>' . t( "Subjects: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->subjects as $subject) {
        if ( $i) {
          $output .= "<br />";
        }
        $output .= '<a href="' . base_path() . 'search/multifacet/' . 
          drupal_urlencode('"' . $subject . '"') .  '&amp;field=subject">' . 
          check_plain($subject) . '</a>';
        $i++;
      }
      $output .= '</td></tr>';
  }

  if ( isset( $doc->urls)) {
      $output .= '<tr><th>' . t( "Online Access: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->urls as $url) {
        $url_info = explode("\t", $url);
        if ( $i) {
          $output .= "<br />";
        }
        $output .= '<a href="' . $url . '">' . 
          check_plain($url) . '</a>';
        $i++;
      }
      $output .= '</td></tr>';
  }

  if ( isset( $doc->item_callnumber)) {
      $output .= '<tr><th>' . t( "Call Number: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->item_callnumber as $item_callnumber) {
        if ( $i) {
          $output .= "<br />";
        }
        $output .= check_plain($item_callnumber);
        $i++;
      }
      $output .= '</td></tr>';
  }
  
  if ( isset( $doc->lc_class)) {
      $output .= '<tr><th>' . t( "LC Classification: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->lc_class as $lc_class) {
        if ( $i) {
          $output .= ", ";
        }
        $output .= '<a href="' . base_path() 
          . 'search/multifacet/*&field=keyword&keep_f=1&fn[]=lc_class&fv[]=' 
          . drupal_urlencode($lc_class) . '">' . check_plain( $lc_class) . '</a>';
        $i++;
      }
      $output .= '</td></tr>';
  }

  if ( isset( $doc->extent)) {
      $output .= '<tr><th>' . t( "Physical Description: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->extent as $extent) {
        if ( $i) {
          $output .= "<br />";
        }
        $output .= check_plain($extent);
        $i++;
      }
      $output .= '</td></tr>';
  }
  
  if ( isset( $doc->notes_public)) {
      $output .= '<tr><th>' . t( "Notes: ")
        . '</th><td>';
      $i = 0;
      foreach ( $doc->notes_public as $notes_public) {
        if ( $i) {
          $output .= "<br />";
        }
        $output .= check_plain($notes_public);
        $i++;
      }
      $output .= '</td></tr>';
  }

  /*
  if ( $doc->source = 'mu-innopac') {
    $output .= '<tr><th>' . t("Other Options: ")
      . '</th><td><a target="_blank" class="external" 
      style="margin-right: 15px;" href="http://holmes.lib.muohio.edu/record=' 
      . drupal_urlencode(substr($doc->$solrpac_unique_key, 5)) . '">' 
      . t('Classic View') . '</a>';
    $output .= '<a target="_blank" class="external" style="margin-right: 15px;"
      href="http://olc1.ohiolink.edu/search/z?' 
      . drupal_urlencode(str_replace("gb", "g b", $doc->$solrpac_unique_key)) 
      . '">' . t('OhioLINK') . '</a>';

    if (isset($doc->id)) {
      $doc->id = preg_replace('/\s/', '', $doc->id);
      $doc->id = preg_replace('/^ocm/', '', $doc->id);
      $doc->id = preg_replace('/^ocn/', '', $doc->id);
      $output .= ' <a target="_blank" class="external"
        href="http://www.worldcat.org/search?q=' 
        . drupal_urlencode("no:" . $doc->id) . '">' . t( "Worldcat") 
        . '</a>';
    }
 
    $output .= '</td></tr>';
  
  }
  */
  
  $output .= '</table></div>';

  return $output;

}

