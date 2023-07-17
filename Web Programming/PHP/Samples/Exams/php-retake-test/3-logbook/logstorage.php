<?php
include_once('storage.php');

class LogStorage extends Storage {
  public function __construct() {
    parent::__construct(new JsonIO('logs.json'));
  }
}