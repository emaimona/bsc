<?php
include_once('storage.php');

class TrackStorage extends Storage {
  public function __construct() {
    parent::__construct(new JsonIO('tracks.json'));
  }
}