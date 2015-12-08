MULtifacet is a Drupal 5 module that wraps a UI around an arbitrary Solr index.
It shares many features with other Solr-based OPAC projects, including faceted
search results, SMS/email output, RefWorks integration, user tagging,
saving/exporting of records, RSS feeds, Zotero support, Google Books
images/linking, "more like this", formatted citation output (via the WorldCat
API), COinS, unAPI, etc. While developed for, and initially targeted at,
library collections, there's no reason it couldn't put a UI on other Solr
indexes that need similar features. There's a bit of ajax, but it should
degrade gracefully.

This module is released under the terms of the GNU General Public License,
version 3.  Other external libraries are provided with their accompanying
licenses.

Copyright (c) 2009 by Miami University Libraries.
released under the terms of the GNU Public License.
see the GPLv3 for details.

Brief description and installation notes can be found in the <a href='http://multifacet.googlecode.com/svn/trunk/README'>README</a>


&lt;hr noshade="noshade" /&gt;



A (likely) working demo is available at http://rcasson.drupal.lib.muohio.edu/search/multifacet

Some caveats
<ul>
<li>Some features are not available to anonymous users</li>
<li>The "advanced" search options will be strange.  They are configured as a bit of a hodge-podge, to illustrate the flexibility</li>
<li>If all else fails, note the title of the site: "rob breaking stuff"</li>
</ul>

A closely linked companion project is <a href='http://code.google.com/p/multifacet-indexer/'>MULtifacet Indexer</a>, a collection of utilities to munge/analyze/etc. MARC records, and III-specific export tools