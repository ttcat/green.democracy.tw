$(document).ready(function() {

	// Responsive Menu.js
	$('#nav-wrap').prepend('<div id="menu-icon"><span><img src="/img/hamburger@2x.png"/></span><b style="color:#FFF" id="nav-word"></b></div>');
	$("#menu-icon").on("click", function(){
		$("#nav").slideToggle('medium', function() {
		    if ($('#nav').is(':visible'))
		        $('#nav').css('display','block');
		    if ($('#nav').is(':hidden'))
		        $('#nav').css('display','');    
		});
		
		$(this).toggleClass("active");
	});
  		


	// Parent-Nav Hover	
	$("li.nav-parent").hover(function(){
		$(this).addClass("hover");
	}, function(){
	    $(this).removeClass("hover");
	});
  	
  	
  	
	// FitVid.js
	$(".main-container").fitVids();  	
  
  	
  	// Stellar-Paralax.js
  	$(window).stellar()
  	
  	
  	// Scrollup.js
  	$.scrollUp({
  	    scrollName: 'scrollUp', // Element ID
  	    topDistance: '300', // Distance from top before showing element (px)
  	    topSpeed: 300, // Speed back to top (ms)
  	    animation: 'fade', // Fade, slide, none
  	    animationInSpeed: 200, // Animation in speed (ms)
  	    animationOutSpeed: 200, // Animation out speed (ms)
  	    scrollText: 'top', // Text for element
  	    activeOverlay: false, // Set CSS color to display scrollUp active point, e.g '#00FFFF'
  	  });
  	
  	
  	
	// Fancybox.js
	$('.fancybox').fancybox();  
 
  	
  	
	// CleanTabs.js	
	$(".tab-container").cleanTabs();	
 

	
	// Toggle	  
	$('.toggle-btn').click(function(e){
		e.preventDefault();
		
//$('.toggle-btn ')$('.issues-like').css('display', 'inline-block');		
		$(this).closest('li').find('.toggle-content').not(':animated').slideToggle();
		
		var myURL = document.location;
		
	    if($(this).attr('hash-id')) { 
	    	
	    	var pathnames = window.location.pathname.split('/');
	    	
			if (history.pushState) {
			    var newurl = window.location.protocol + "//" + window.location.host + '/' + pathnames[1] + '/issues/nid/' + $(this).attr('hash-id');
			    window.history.pushState({path:newurl},'',newurl);
			}	    
	   
	   		var hashfb = '#fb' + $(this).attr('hash-id');
	   		$(hashfb).css('display', 'inline-block');
	    //window.location.hash = $(this).attr('hash-id'); 
	    
	    }

	});
	
	// Add Class for Toggle
	$(".toggle-btn").click(function () {
	$(this).toggleClass("active");
	});
  
  
  
	// Accordion	  
	$('.accordion-btn').click(function(e){
		e.preventDefault();
		$this = $(this);
		$thisAccordionContent = $this.closest('li').find('.accordion-content');
		var currentStatus = "";
		if ($this.attr('class').indexOf('active') != -1) {
			currentStatus = "active";
		}
		//first close all and remove active class
		$this.closest('.accordion').find('li').each(function(index) {
			$thisLi = $(this);
			$thisLi.find('.accordion-btn').removeClass('active');
			$thisLi.find('.accordion-content').slideUp('400', function() {
				$(this).removeClass('active');
			});
		});
		if (currentStatus != "active") {
			$thisAccordionContent.not(':animated').slideDown();
			$this.addClass('active');
			$thisAccordionContent.addClass('active');
		}
	});
	
	  
  
	// Mosaic.js		 
	$('.fade').mosaic();
	 
 	 
  
  	// FlexSlider.js	 
	$('.flexslider').flexslider({
		animation: "fade",
	   	smoothHeight: false,
	   	touch: true,
	   	prevText: "S",
	   	nextText: "s",
	   	start: function(slider){
	    $('body').removeClass('loading');
	  }
	});
	 
	 
	$('.flexslider-quote').flexslider({
	  animation: "fade",
	  smoothHeight: true,
	  touch: true,
	  directionNav: false,
	  start: function(slider){
	    $('body').removeClass('loading');
	  }
	});
	 

	$('#nav-word').html('挺好的！');
    $(window).scroll(sticky_relocate);
    sticky_relocate();
	 
	 
$("#subscribe-newsletter").	validate({
  	rules: {
  		email: {
  			required: true,
  			email: true
  		}
  	},  	
  	messages: {
  		email: {
  			required: "請填寫您的 Email",
  			email: "請檢查您的 Email"
  		}
  	}
  	
});			
	 

/*	
	// Isotope.js	 
	var $container = $('#thumb-gallery');
	  
	    $container.isotope({
	      masonry: {
	        columnWidth: 1 //was 26
	      },
	      sortBy: 'number',
	      getSortData: {
	        number: function( $elem ) {
	          var number = $elem.hasClass('element') ? 
	            $elem.find('.number').text() :
	            $elem.attr('data-number');
	          return parseInt( number, 10 );
	        },
	        alphabetical: function( $elem ) {
	          var name = $elem.find('.name'),
	              itemText = name.length ? name : $elem;
	          return itemText.text();
	        }
	      }
	    });	     

	var $optionSets = $('.meta.option-set'),
	          $optionLinks = $optionSets.find('a');
	
	      $optionLinks.click(function(){
	        var $this = $(this);
	        // don't proceed if already selected
	        if ( $this.hasClass('selected') ) {
	          return false;
	        }
	        var $optionSet = $this.parents('.option-set');
	        $optionSet.find('.selected').removeClass('selected');
	        $this.addClass('selected');
	  
	        // make option object dynamically, i.e. { filter: '.my-filter-class' }
	        var options = {},
	            key = $optionSet.attr('data-option-key'),
	            value = $this.attr('data-option-value');
	        // parse 'false' as false boolean
	        value = value === 'false' ? false : value;
	        options[ key ] = value;
	        if ( key === 'layoutMode' && typeof changeLayoutMode === 'function' ) {
	          // changes in layout modes need extra logic
	          changeLayoutMode( $this, options )
	        } else {
	          // otherwise, apply new options
	          $container.isotope( options );
	        }
	        
	        return false;
	      });
	      
	      
	  // initialize Isotope after all images have loaded
	  var $container = $('#thumb-gallery').imagesLoaded( function() {
	    $container.isotope({
	      // options
	    });
	  });    	       
*/	       
	       	          	 
// End Call	 
});

function sticky_relocate() {
    var window_top = $(window).scrollTop();
    var div_top = $('#sticky-anchor').offset().top;
    var div_height = $('.header-container').height();
	
	if($(window).width() < 480) {  div_height = 51; }
	
    if (window_top > div_top - div_height) {
        $('#navall').addClass('stick');
        
		if($(window).width() < 480) { $('#nav-word').css('display', 'none'); $('#menu-icon').width('22px'); $('#menu-icon').width('100%'); $('#nav-wrap').width('20'); }
        if($(window).width() >= 480) { $('#nav-word').css('display', 'inline-block'); $('#menu-icon').width('auto'); $('#nav-word').html('挺好的！'); $('#nav-wrap').width('auto');}

		$('#first-nav').html('認識');
       	$('#logo-word').html($('#thisname').html());
       	
       	$('#space').height(div_height);
        
    }
    
    
    if (window_top <= div_top) {
        $('#navall').removeClass('stick');
        
    	if($(window).width() < 480) { $('#nav-word').css('display', 'inline-block'); $('#menu-icon').width('100%'); $('#nav-wrap').width('147'); }
        if($(window).width() >= 480) { $('#nav-word').css('display', 'inline-block'); $('#menu-icon').width('auto'); $('#nav-word').html('挺好的！'); $('#nav-wrap').width('auto');}
		
        $('#first-nav').html('認識' + $('#thisname').html());
        $('#logo-word').html('');        

       	$('#space').height(0);
                
    }
}


		var _gaq=[['_setAccount','UA-XXXXX-X'],['_trackPageview']];
		(function(d,t){var g=d.createElement(t),s=d.getElementsByTagName(t)[0];
		g.src=('https:'==location.protocol?'//ssl':'//www')+'.google-analytics.com/ga.js';
		s.parentNode.insertBefore(g,s)}(document,'script'));