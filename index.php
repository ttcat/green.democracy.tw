<?php
global $u;
$q = ltrim($_SERVER['REQUEST_URI'], '/');
$q = preg_replace('/[^a-zA-Z0-9]\//', '', $q);
list($u, $f) = explode('/', $q, 2);
if(file_exists($f.'.inc')){
  include_once($f.'.inc');
}
