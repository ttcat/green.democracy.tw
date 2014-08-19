<?php
global $u;
$q = ltrim($_SERVER['REQUEST_URI'], '/');
$q = preg_replace('/[^a-zA-Z0-9]\//', '', $q);

list($u, $f, $key, $vaule) = explode('/', $q, 4);

	if($key == 'nid') {	
	 	$value = explode('?' ,$value, 2);
		if(is_numeric($value[0])) {
			$nid = filter_var($value[0], FILTER_SANITIZE_NUMBER_INT);
			print_r($nid);
			$query_this_page = $value[1]; //參數待處理 sql-injection
		}
	}
	
	if($f == 'api') {
	 	$key = explode('?' ,$key, 2);
	 	if($key[	0] == 'timeline') {
	 		$timeline_page_query = $key[1]; //參數待處理 sql-injection
	 		include_once('api/timeline.inc');
			exit();
		}
	}
	
$f = explode('?' ,$f, 2);
//預設 politician.inc 為首頁
if($f[0] == null) {
  include_once('politician.inc');
  exit();
}
if(file_exists($f[0].'.inc')){
  include_once($f[0].'.inc');
  exit();
}
?>
<html>
<head>
<meta http-equiv="content-type" content="text/html;charset=utf-8">
<title>Error 404 Not Found</title>
<style>
<!--
  body {font-family: arial,sans-serif}
  img { border:none; }
//-->
</style>
</head>
<body>
<div align="center">
<h1>404 Not Found</h1>
<hr>
Nginx
</div>
</body>
</html>
