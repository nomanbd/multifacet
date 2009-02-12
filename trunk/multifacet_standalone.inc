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

function multifacet_search_standalone() {
  //drupal_set_html_head('<script src="http://books.google.com/books/previewlib.js" type="text/javascript"></script>');
  global $_pazpar_search_term;
  
  $output = drupal_get_form('multifacet_search_standalone_form', arg(2));

  if (arg(2)) {
    $results =  _multifacet_search(arg(2));

    if (arg(2) != '*' && arg(2) != '*:*') {
      $_pazpar_search_term = arg(2);
    }

    $output .= multifacet_search_page( $results);
  }
  
  return $output;

}

function multifacet_search_standalone_form($keys = NULL) {

  global $_multifacet_default_search_field, $_multifacet_search_fields, 
    $_multifacet_default_sort_field, $_multifacet_sort_fields, $user,
    $_multifacet_advanced_limits, $_multifacet_available, 
    $_multifacet_tagger_facet, $_multifacet_tag_facet, $_multifacet_help_url,
    $multifacet_breadcrumbs, $multifacet_url_append;

  $js = "var Drupal_base_path = '". base_path() ."';";
  drupal_add_js($js, 'inline');

  drupal_set_html_head('<link rel="unapi-server" type="application/xml" 
    title="unAPI" href="http://'. $_SERVER['SERVER_NAME'] . base_path() 
    .'multifacet/unapi/"/>') ;
  drupal_set_html_head('<link rel="search" 
    type="application/opensearchdescription+xml" 
    title="MULtifacet"
    href="http://'. $_SERVER['HTTP_HOST'] . base_path() 
    .'multifacet/opensearch.xml" />') ;
  drupal_add_css(drupal_get_path('module', 'multifacet') .'/multifacet.css');
  
  drupal_add_js(drupal_get_path('module', 'multifacet') . 
    '/jquery.nyroModal-1.3.1.pack.js');
  $js = "$(function() { 
    $.nyroModalSettings({
      titleFromIframe: false
    });
  })";
  drupal_add_js($js, 'inline');

  drupal_add_js(drupal_get_path('module', 'multifacet') . 
    '/jquery-ui.js');
  drupal_add_js(drupal_get_path('module', 'multifacet') . 
    '/jquery.jqURL.js');
  drupal_add_js(drupal_get_path('module', 'multifacet') . 
    '/jquery.multifacet.js');
  drupal_add_css(drupal_get_path('module', 'multifacet') .'/nyroModal.css');
  
  if ( $_multifacet_search_fields[$_GET['field']]) {
    $search_default = $_GET['field'];
  }
  else {
    $search_default = $_multifacet_default_search_field;
  }

  if ( $_multifacet_sort_fields[$_GET['sort']]) {
    $sort_default = $_GET['sort'];
  }
  else {
    $sort_default = $_multifacet_default_sort_field;
  }

  /*
   * FIXME (?)
   *
   * feels hacky, having to generate
   * these here, and pass them around
   * globally
   */
  if ($keys) {
    $multifacet_breadcrumbs = _multifacet_build_breadcrumbs( $_GET);
    $multifacet_url_append = 
      $multifacet_breadcrumbs[count($multifacet_breadcrumbs) - 1]['path'];
  }

  for ( $i = 0; $i < count( $multifacet_breadcrumbs); $i++) {
    $multifacet_breadcrumbs_output .= '<span class="multifacet_breadcrumb">
      <a href="'. $multifacet_breadcrumbs[$i]['path'] 
      .'">'. $multifacet_breadcrumbs[$i]['label'] .'</a> ';

    if ( $multifacet_breadcrumbs[$i]['drop_path']) {
      $multifacet_breadcrumbs_output .= '<a href="' 
        . $multifacet_breadcrumbs[$i]['drop_path'] 
        .'">'. $multifacet_breadcrumbs[$i]['drop_label'] .'</a> ';

    }
    $multifacet_breadcrumbs_output .= '</span>';
  }

  $form = array(
    '#action' => url("search/multifacet", NULL, NULL, TRUE),
    '#attributes' => array('class' => 'search-form'),
    '#base' => 'search_form',
  );

  if ( $_multifacet_help_url) {
    $form['help_url'] = array(
      '#type' => 'markup',
      '#value' => '<a href="'. $_multifacet_help_url .'">'. t("Help") 
        .'</a>',
    );
  }

  /*
   * FIXME (?)
   *
   * this is very hackish, and i don't
   * like it.
   *
   */
  if ( count($_REQUEST['fn'])) {
    $form['fn'] = array(
      '#type' => 'hidden',
      '#value' => serialize( $_REQUEST['fn']),
    );
    $form['fv'] = array(
      '#type' => 'hidden',
      '#value' => serialize( $_REQUEST['fv']),
    );
  }

  if ( count( $multifacet_breadcrumbs)) {
    $form['breadcrumbs'] = array(
      '#type' => 'markup',
      '#value' => '<div id="multifacet_breadcrumbs">' 
        . t("You searched for: ") . $multifacet_breadcrumbs_output .'</div>',
    );
  }

  $form['basic']['inline']['keys'] = array(
    '#type' => 'textfield',
    '#title' => '',
    '#default_value' => $keys,
    '#size' => 30,
    '#maxlength' => 255,
  );

  if ( count( $_multifacet_search_fields)) {
    while ( list( $key, $values) = each ($_multifacet_search_fields)) {
      $search_fields_list[$key] = $values['label'];
    }
    reset($_multifacet_search_fields);
    
    $form['field'] = array(
      '#type' => 'select',
      '#options' => $search_fields_list,
      '#default_value' => $search_default,
    );
  }

  if ( count( $_multifacet_sort_fields)) {
    while ( list( $key, $values) = each ($_multifacet_sort_fields)) {
      $sort_fields_list[$key] = $values['label'];
    }
    reset($_multifacet_sort_fields);
    
    $form['sort'] = array(
      '#type' => 'select',
      '#options' => $sort_fields_list,
      '#default_value' => $sort_default,
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  if ( $_multifacet_available || count( $_REQUEST['fn'])) {
    $form['break1'] = array(
      '#value' => '<br />',
    );
  }

  if ($_multifacet_available) {
    $form['avail'] = array(
      '#type' => 'checkbox',
      '#title' => t('Available'),
      '#default_value' => $_GET['avail'],
    );
  }

  if ( count( $_REQUEST['fn'])) {
    $form['keep_f'] = array(
        '#type' => 'checkbox',
        '#title' => t("Keep filters on search"),
        '#default_value' => $_GET['keep_f'],
        );
  }

  if ( $_multifacet_tagger_facet || $_multifacet_tag_facet 
      && ( $_GET['tagger'] || $_GET['tag'])) {
    $form['break2'] = array(
      '#value' => '<br />',
    );
  }

  if ( $_multifacet_tagger_facet) {
    if ( $_GET['tagger']) {
      $form['tagger'] = array(
          '#type' => 'checkbox',
          '#title' => '<strong>'. $_multifacet_tagger_facet['label'] 
            .": </strong>". $_GET['tagger'],
          '#default_value' => $_GET['tagger'],
          '#return_value' => $_GET['tagger'],
          );
    }
  }

  if ( $_multifacet_tag_facet) {
    if ( $_GET['tag']) {
      $form['tag'] = array(
          '#type' => 'checkbox',
          '#title' => '<strong>'. $_multifacet_tag_facet['label'] 
          .": </strong>". $_GET['tag'],
          '#default_value' => $_GET['tag'],
          '#return_value' => $_GET['tag'],
          );
    }
  }

  if ( count( $_multifacet_advanced_limits)) {

    $form['advanced'] = array(
      '#type' => 'fieldset',
      '#title' => t( "Advanced Options"),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    
    while ( list( $key, $values) = each ($_multifacet_advanced_limits)) {
      while ( list($type, $info) = each ( $values)) {
        $options[$type] = $info['label'];
        // url has passed a valid value, so expand the fieldset
        if ( $_GET[$key] == $type && isset( $_GET[$key])) {
          $expanded = 1;
        }
      }
      $form['advanced']['limits'][$key] = array(
        '#title' => $key,
        '#type' => 'radios',
        '#options' => $options,
        '#default_value' => $_GET[$key],
      );
      unset( $options);
    }

    if ( $expanded) {
      $form['advanced']['#collapsed'] = FALSE;
    }

    reset($_multifacet_advanced_limits);
  
  }

  $form['#submit']['multifacet_search_form_submit'] = array();

  return $form;

}
