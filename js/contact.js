$(function() {
	// Validate the contact form	
  $('#contactform').validate({
  	// Specify what the errors should look like
  	// when they are dynamically added to the form
  	errorElement: "label",
  	wrapper: "td",
  	errorPlacement: function(error, element) {
  		error.insertBefore( element.parent().parent() );
  		error.wrap("<tr class='error'></tr>");

  	},
  	
  	// Add requirements to each of the fields
  	rules: {
  		name: {
  			required: true,
  			minlength: 2
  		},

			phone: {
				 required: true,
			      digits: true,
			      twphone: true
			},

  		email: {
  			required: true,
  			email: true
  		},
  		message: {
  			required: true,
  			minlength: 5
  		}
  	},
  	
  	// Specify what error messages to display
  	// when the user does something horrid
  	messages: {
  		name: {
  			required: "請輸入您的姓名",
  			minlength: jQuery.format("至少 {0} 個字元")
  		},
  		email: {
  			required: "請填寫您的 Email",
  			email: "請檢查您的 Email"
  		},
  		phone: {
  			required: "請填寫您的手機",
  			digits: "只能填寫數字",
     	     twphone: "請填寫正確手機號碼"
  			
  		},
  		message: {
  			required: "請輸入您的選區",
  			minlength: jQuery.format("至少 {0} 個字元")
  		}
  	},
  	
  	// Use Ajax to send everything to processForm.php
  	submitHandler: function(form) {
  		$("#send").attr("value", "送出中...");
  		$(form).ajaxSubmit({
  			success: function(responseText, statusText, xhr, $form) {
  				$(form).slideUp("fast");
  				$("#response").html(responseText).hide().slideDown("fast");
  			}
  		});
  		return false;
  	}
  });
});