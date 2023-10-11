Views Menu Support (VMS)
========================

Views Menu Support provides a Views filter handler and a default argument
plugin, allowing for filtering on currently active menu item(s). You can filter
on the current item, the whole active menu trail, or the menu trail excluding
the current item.

A submodule (Menu Item Reference Widget) is included which allows populating
integer fields with menu item IDs, picked from a select list.

Together, these modules allow you to reference menu items where content should
be visible, then display that specific content on those specific menu
items/pages using Views. For examples, check out the
[VMS Wiki](https://github.com/backdrop-contrib/vms/wiki/Example-setup).

Installation
------------

- Install this module, and the Menu Item Reference Widget submodule, using the
  official Backdrop CMS instructions at https://backdropcms.org/guide/modules.

- Add an integer field with the Menu Item Reference Widget to a content type.

- Create a view and add the 'MLID filtering' filter for your integer field.

- Configure both appropriately.

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/vms/issues.

Current Maintainers
-------------------

- Seeking maintainer(s)

Credits
-------

- Ported to Backdrop CMS by [Peter Anderson](https://github.com/BWPanda).
- Originally written for Drupal by [Johan Falk](https://github.com/Itangalo).

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

