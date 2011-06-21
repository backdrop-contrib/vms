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
    if (isset($menu_item['mlid'])) {
      return $menu_item['mlid'];
    }
    else {
    // We don't have any active menu item, probably meaning that we are at the
    // front page.
      if (drupal_is_front_page()) {
        // Return -1 to signal that we are at the front page.
        return -1;
      }
    }

    // If we got here, then we are not at the front page, but there is still no
    // mlid present. Return -2 to signal that something is wrong.
    return -2;
  }
}
