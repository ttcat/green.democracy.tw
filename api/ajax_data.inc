<?php
    $year = $_POST['year'];

    $data = array(
        array(
            'type'    =>  'blog_post',
            'date'    =>  $year . '-12-21',
            'title'   =>  'Blog Post',
            'content' => '<b>Lorem Ipsum</b> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.'
        ),
        array(
            'type'    =>  'blog_post',
            'date'    =>  $year . '-11-21',
            'title'   =>  'Blog Post',
            'content' => '<b>Lorem Ipsum</b> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.'
        ),
        array(
            'type'    =>  'blog_post',
            'date'    =>  $year . '-10-21',
            'title'   =>  'Blog Post',
            'content' => '<b>Lorem Ipsum</b> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.'
        ),
        array(
            'type'    =>  'blog_post',
            'date'    =>  $year . '-09-21',
            'title'   =>  'Blog Post',
            'content' => '<b>Lorem Ipsum</b> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry\'s standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.'
        )
    );

    print json_encode($data);
?>