<?php
/**
 * @file
 * Contains the php code argument default plugin.
 */

/**
 * Default argument plugin to provide current mlid item.
 */
class vms_plugin_argument_default_mlid extends views_plugin_argument_default {
  function get_argument() {
    // Get the current active menu link ID and return it.
    $menu_item = array_pop(menu_set_active_trail());
    return $menu_item['mlid'];
  }
}
