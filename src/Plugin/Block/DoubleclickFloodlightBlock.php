<?php

namespace Drupal\doubleclick_floodlight\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Component\Utility\SafeMarkup;

use Drupal\Component\Utility\String;


/**
 * Provides a 'Doubleclick Floodlight' block.
 *
 * @Block(
 * id = "doubleclick_floodlight",
 * admin_label = @Translation("Doubleclick Floodlight"),
 * )
 */
class DoubleclickFloodlightBlock extends BlockBase {
  /**
   * {@inheritdoc}
   */
  public function build() {

//        $config = $this->getConfiguration();

    return array(
//      '#type'=>'markup',
//      '#markup' =>' <h1>not working</h1>',
      '#account_id' => '123',
      '#type' => '456',
      '#cat' => '789',
    );
  }
}
