<?php
error_reporting(E_ALL & ~E_NOTICE);

global $u,$nid,$page;
$q = $_SERVER['REDIRECT_URL'] ? ltrim($_SERVER['REDIRECT_URL'], '/') : ltrim($_SERVER['REQUEST_URI'], '/');
if(strstr($q, '?')){
  $q = substr($q, 0, strpos($q, '?'));
}
$q = preg_replace('/[^a-zA-Z0-9]\//', '', $q);

list($u, $f, $nid) = explode('/', $q, 3);

/**
 * 1. verify user
 * TODO: should be only accept listed user for greenparty
 */
$u = str_replace('.php', '', $u);
if(empty($u)){
  header("HTTP/1.0 404 Not Found");
  include('404.html');
  exit();
}

/**
 * verify section
 */
if(empty($f)){
  $f = 'politician';
  $section = $f;
}

switch($f){
  case 'timeline':
    if(!empty($nid) && is_numeric($nid)){
      
    }
    else{
      $nid = null;
    }

    // require api here
    require_once 'api/api.inc';
    $page = !empty($_GET['p']) ? $_GET['p'] : 0;
    if(is_numeric($page) || $page === 'all'){
      require_once('api/timeline.inc');
      $section = 'timeline';
      print get_timeline();
      exit();
    }
    break;
  default:
    if(!empty($nid) && is_numeric($nid)){
      
    }
    else{
      $nid = null;
    }
    // require api here
    require_once 'api/api.inc';
    if(file_exists($f.'.inc')){
      include_once($f.'.inc');
      $section = $f;
      exit();
    }
    break;
}

// 404 should always static for performance reason(too bad)
header("HTTP/1.0 404 Not Found");
include('404.html');
exit();

