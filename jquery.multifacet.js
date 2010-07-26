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

// Global killswitch: only run if we are in a supported browser.
if (Drupal.jsEnabled) {


  /*
   * convenience function
   * to replace weird characters
   * for jquery processing
   */
  function jq(myid) {
    return myid.replace(/:/g,"\\:").replace(/\./g,"\\.");
  }

  function multifacet_clear_marked(clear) {
    $.getJSON(Drupal_base_path + 'multifacet/marked_clear_ajax/' + clear,
      function(data) {
        $("#multifacet_marked_clear_message").html(data.label);
        if (data.add_label) {
          $('.multifacet_mark_link').html(data.add_label);
        }
        if ( data.block_label) {
          $('#multifacet_marked_block').html(data.block_label);
          $('#multifacet_marked_clear').html(data.clear_label);
          // disable/re-enable the entire form?
          $('#multifacet_export_submit').attr('disabled', true);
          $('#multifacet_export_options').attr('disabled', true);
          $('#multifacet_export_email').attr('disabled', true);
        } else {
          $('#multifacet_export_submit').attr('disabled', false);
          $('#multifacet_export_options').attr('disabled', false);
          $('#multifacet_export_email').attr('disabled', false);
        }
        setTimeout("parent.$.nyroModalRemove()", 1000);
      });
  }

  function multifacet_export () {
    if ($('#multifacet_export_options option:selected').val() != 'email') {
      $('#multifacet_export_email').attr('disabled', true);
      if ($('#multifacet_export_options option:selected').val() != 'refworks') {
        $('#multifacet_marked_form').attr('target', 'multifacet_export');
      } else {
        $('#multifacet_marked_form').attr('target', 'RefWorksMain');
      }
    } else {
      $('#multifacet_export_email').attr('disabled', false);
      $('#multifacet_marked_form').attr('target', '');
    }

  }

  function multifacet_mark_ajax (id) {
    $.getJSON(Drupal_base_path + 'multifacet/mark_ajax/' + id,
      function(data) {
        var href_id = '#' + jq(id) + '_mark_form';
        //setTimeout("$('" + href_id + "').val('" + data.label + "')", 300);
        $(href_id).html(data.label);
        $('#multifacet_marked_block').html(data.block_label);
        $('#multifacet_marked_clear').html(data.clear_label);
        $('#multifacet_marked_clear a').nyroModal();
        if (data.count) {
          $('#multifacet_export_submit').attr('disabled', false);
          $('#multifacet_export_options').attr('disabled', false);
          if ($('#multifacet_export_options option:selected').val() == 'email') {
            $('#multifacet_export_email').attr('disabled', false);
          }
        } else {
          $('#multifacet_export_submit').attr('disabled', true);
          $('#multifacet_export_options').attr('disabled', true);
          $('#multifacet_export_email').attr('disabled', true);
        }
      });
  }

  function multifacet_sms_ajax (id, number, carrier) {
    $.getJSON(Drupal_base_path + 'multifacet/sms_ajax/' + id + '/' + number
      + '/' + carrier,
      function(data) {
        $("body").append("<div>" + data.label + "</div>");
        setTimeout("parent.$.nyroModalRemove()", 1000);
      });
  }

  function multifacet_tag_ajax (id, tags) {
    $.getJSON(Drupal_base_path + 'multifacet/tag_ajax/' + id + '/' + tags,
      function(data) {
        id = jq(id);
        $("body").append("<div>" + data.label + "</div>");
        if (data.tags) {
          parent.$("span#multifacet_your_tags_" + id).html(data.tags);
          parent.$("div#multifacet_user_tags_" + id).show();
        } else {
          parent.$("span#multifacet_your_tags_" + id).html("");
          parent.$("div#multifacet_user_tags_" + id).hide();
        }

        if (data.public_tags) {
          parent.$("span#multifacet_public_tags_" + id).html(data.public_tags);
          parent.$("div#multifacet_public_tags_div_" + id).show();
        } else {
          parent.$("span#multifacet_public_tags_" + id).html("");
          parent.$("div#multifacet_public_tags_div_" + id).hide();
        }

        if (data.taggers) {
          parent.$("span#multifacet_taggers_" + id).html(data.taggers);
          parent.$("div#multifacet_taggers_div_" + id).show();
        } else {
          parent.$("span#multifacet_taggers_" + id).html("");
          parent.$("div#multifacet_taggers_div_" + id).hide();
        }

        setTimeout("parent.$.nyroModalRemove()", 1000);

      });
  }

  function multifacet_toggle_facets(facet) {
    $.getJSON(Drupal_base_path + 'multifacet/toggle_facets/' + facet,
      function(data) {
        facet = jq(facet);
        if (data.toggle == 'collapsed') {
          $('dl#' + facet + '_facet_dl').hide(); 
          $('a#' + facet + '_toggle_link').removeClass('multifacet_expanded_link').addClass('multifacet_collapsed_link'); 
        } else {
          $('dl#' + facet + '_facet_dl').show();
          $('a#' + facet + '_toggle_link').removeClass('multifacet_collapsed_link').addClass('multifacet_expanded_link'); 
        }
        //$('#' + facet + '_facet_image').attr("src", data.img);
        $('#' + facet + '_facet_image').attr("alt", data.label);
      });
  }

  function multifacet_toggle_more_less (facet) {
    facet = jq(facet);
    $('#' + facet + '_facet_dl').find('dt.multifacet_facet_hidden').toggle();
    return(void(0));
  }

  function multifacet_toggle_all_facets(state) {
    $.getJSON(Drupal_base_path + 'multifacet/toggle_all_facets/' + state,
      function(data) {
        if (data.toggle == 'collapsed') {
          $("dl.multifacet_facet_list").hide();
          $('a.multifacet_facet_toggle').removeClass('multifacet_expanded_link').addClass('multifacet_collapsed_link'); 
        } else {
          $("dl.multifacet_facet_list").show();
          $('a.multifacet_facet_toggle').removeClass('multifacet_collapsed_link').addClass('multifacet_expanded_link'); 
        }
        //$("img.multifacet_facet_image").attr("src", data.img);
        $("img.multifacet_facet_image").attr("alt", data.label);
      });
  }

  function multifacet_hideall_facets() {
    $("ul.multifacet_facet_list").hide();
  }

  function ProcessGBSBookInfo(booksInfo) {
    for (bibKey in booksInfo) {
      var bookInfo = booksInfo[bibKey];
      if (bookInfo) {
        var label= '#' + jq(bibKey);
        var img = "";
        if ( bookInfo.thumbnail_url) {
          img = '<img border="0" src="' + bookInfo.thumbnail_url 
            + '" alt="Thumbnail Image for ' + bibKey + '" /><br />';
        }
        if (bookInfo.preview == "full" || bookInfo.preview == "partial") {
          $(label).attr("href", bookInfo.preview_url);
          $(label).show();
          if ( bookInfo.preview == "full") {
            $(label).html(img + "Read at Google");
          } else {
            $(label).html(img + "Preview at Google");
          }
        } else if ( bookInfo.info_url) {
          $(label).attr("href", bookInfo.info_url);
          $(label).html(img + "Extra Information at Google");
          $(label).show();
        }
      }
    }
  }
  
  function multifacet_resort() {
    var resort = new Array();
    resort["sort"] = $("#multifacet_resort_list option:selected").val()
    resort["pageID"] = 1
    var url = $.jqURL.set(resort);
    window.location = url;
  }

  $(document).ready(function() {
    $('.multifacet_browse_div').hide();
    $('#multifacet_resort').show();
    $("#multifacet_browse_option").change(function() {
      var table = $("#multifacet_browse_option option:selected").val();
      if (table) {
        $('#multifacet_browse_wrapper').html($('#' + table + '_browse_div').html());
        $('#' + table + '_browse_table').tablesorter({widgets: ['zebra']});
      }
    })
    .trigger('change');
  });
}

