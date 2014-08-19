<?php
global $u;
$q = ltrim($_SERVER['REQUEST_URI'], '/');
$q = preg_replace('/[^a-zA-Z0-9]\//', '', $q);
list($u, $f) = explode('/', $q, 2);
if(file_exists($f.'.inc')){
  include_once($f.'.inc');
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
