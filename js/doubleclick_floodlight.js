/**
 * @file
 * Attaches several event listener to a web page.
 */

(function ($, Drupal, drupalSettings) {

//  "use strict";

  Drupal.doubleclick_floodlight = {};
console.info(drupalSettings.doubleclick_floodlight);

  $(document).ready(function () {
      if (drupalSettings.doubleclick_floodlight.enabled) {
console.info('enabled');
}


 return "<script>alert('hello world');</script>";


    });


})(jQuery, Drupal, drupalSettings);
