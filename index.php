<?php
global $u;
$q = ltrim($_SERVER['REQUEST_URI'], '/');
$q = preg_replace('/[^a-zA-Z0-9]\//', '', $q);

//$pos = strpos($q, '?');
//if ($pos === false) {
	//} else {
//}


list($u, $f, $key, $value) = explode('/', $q, 4);

exit();

	if($key == 'nid') {	// 個別單元吃 nid
	 	$value_array = explode('?' ,$value, 2);
		if(is_numeric($value_array[0])) {	
			$nid = filter_var($value_array[0], FILTER_SANITIZE_NUMBER_INT);
			$query_this_page = $value_array[1]; //參數待處理 sql-injection
			$current_url = $u.'/'.$f.'/nid/'.$nid;
			$page_key = $nid;			
		}
	}
	
	if($f == 'nid') {	//timeline 首頁吃 nid
	 	$key_array = explode('?' ,$key, 2);
		if(is_numeric($key_array[0])) {	
			$nid = filter_var($key_array[0], FILTER_SANITIZE_NUMBER_INT);
			$query_this_page = $key_array[1]; //參數待處理 sql-injection
			$current_url = $u.'/nid/'.$nid;
			$page_key = $nid;			
		}
		include_once('politician.inc');
		exit();
	}	
	
	if($f == 'api') { // api read
	 	$key_array = explode('?' ,$key_array, 2);
	 	if($key_array[0] == 'timeline') {
	 		$timeline_page_query = $key_array[1]; //參數待處理 sql-injection
			$current_url = $u.'/api/timeline';
	 		include_once('api/timeline.inc');
			exit();
		}
	}

$f_array = explode('?' ,$f, 2);
//預設 politician.inc 為首頁
if($f_array[0] == null) {
  $current_url = $u;
  $section = 'index';
  include_once('politician.inc');
  exit();
}

if(file_exists($f_array[0].'.inc')){
  $current_url = $u.'/'.$f_array[0];
  $section = $f_array[0];
  include_once($f_array[0].'.inc');
  exit();
}

  include_once('404.inc');
  exit();
?>

