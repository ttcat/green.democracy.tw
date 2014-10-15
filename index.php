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
 
 $all_users = array('wangchungming', 'ellen', 'muwan', 'tang', 'chungli2014', 'rober86', 'jaywin2014', 'star', 'afu', 'antung');
 $u = str_replace('.php', '', $u);

foreach ($all_users as $k => $user) {
	if($user == $u) {
		$found = 1;
	}
}

if($u == 'redir' && empty($f)){
	$f = 'redir';
	include('api/redir.inc');
	exit();
}

if($u == 'about' && empty($f)){
	$f = 'about';
	include('about.inc');
	exit();
}

if(empty($found) && $u) {
  header("HTTP/1.0 404 Not Found");
  include('404.html');
  exit();
}

if(empty($u)){
	$f = 'index';
    require_once 'api/api.inc';
	include('index.inc');
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
    $section = 'timeline';
  
    if(!empty($nid) && is_numeric($nid)){
      
    }
    else{
      $nid = null;
    }

    // require api here
    require_once 'api/api.inc';
    $page = !empty($_GET['p']) ? $_GET['p'] : 1;
    if(is_numeric($page) || $page === 'all'){
      require_once('api/timeline.inc');
      print get_timeline();
      exit();
    }
    break;
    
  default:
    $section = $f;
    if(!empty($nid) && is_numeric($nid)){
      
    }
    else{
      $nid = null;
    }
    // require api here
    require_once 'api/api.inc';
    if(file_exists($f.'.inc')){
      include_once($f.'.inc');
      exit();
    }
    break;
}

// 404 should always static for performance reason(too bad)
header("HTTP/1.0 404 Not Found");
include('404.html');
exit();

