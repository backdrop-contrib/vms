<?php
/**
 * @file
 * Contains the php code argument default plugin.
 */

/**
 * Default argument plugin to provide current mlid item.
 */
class vms_plugin_argument_default_mlid extends views_plugin_argument_default {
  function option_definition() {
    $options = parent::option_definition();
    $options['trail'] = array('default' => 'current');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['trail'] = array(
      '#type' => 'select',
      '#title' => t('Menu item(s) to return'),
      '#default_value' => $this->options['trail'],
      '#options' => array(
        'current' => t('Currently active mlid'),
        'trail' => t('Currently active mlid plus trail to top'),
        'exclude_current' => t('Trail to top menu link item, excluding the current mlid'),
      ),
      '#description' => t('Select which mlid should be fetched. Note that if a
        trail is included, the mlids will be built on the form 1+2+3. Make sure
        to enable the option for handling multiple values in this argument
        accordingly.'),
    );

  }

  function get_argument() {
    // Front page is a special case, and doesn't have any mlid. This is handled
    // separately, to allow some smoother process below.
    if (drupal_is_front_page ()) {
      if ($this->options['trail'] == 'current_exclude') {
        return VMS_MLID_MISSING;
      }
      else {
        return VMS_FRONT_PAGE;
      }
    }

    // Get the current active menu link trail.
    $menu_trail = menu_set_active_trail();

    // Note that this operation *removes* an item from the array it works with,
    // while also populating the new variable.
    $current_menu_item = array_pop(&$menu_trail);

    // Set a fake mlid for the first entry, corresponding to the front page.
    $menu_trail[0]['mlid'] = VMS_FRONT_PAGE;

    if (!isset($current_menu_item['mlid'])) {
      // If we don't have any active menu item, and we're NOT at the front page,
      // something is awry. Return -2 to allow recognizing this.
      return VMS_MLID_MISSING;
    }

    // Check the different configuration cases, and return mlids accordingly.
    switch ($this->options['trail']) {
      case 'current' : {
        return $current_menu_item['mlid'];
      }

      case 'trail' : {
        $mlids = array();
        foreach ($menu_trail as $menu_item) {
          $mlids[] = $menu_item['mlid'];
        }
        $mlids[] = $current_menu_item['mlid'];

        return implode('+', $mlids);
      }

      case 'exclude_current' : {
        $mlids = array();
        foreach ($menu_trail as $menu_item) {
          $mlids[] = $menu_item['mlid'];
        }

        return implode('+', $mlids);
      }
    }

    // If we got here, something is really wrong. For example with the
    // configured options for the default argument.
    return VMS_MLID_MISSING;
  }
}
