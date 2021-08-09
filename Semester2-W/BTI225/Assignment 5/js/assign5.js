function returnFormValidation(value)
{
	function passwordAlert(pass)
	{
		var check = 0;
		temp = pass.password.value;
		if (temp.match(/.*(?=.*?[A-Z]).*/) == null) 
		{
			alert("Password must contain at least 1 capital letter.");
			check = 1;
			return false;
		}
		if (temp.match(/.*(?=.*?[a-z]).*/) == null) 
		{
			alert("Password must contain at least 1 lower letter.");
			check = 1;
			return false;
		}
		if (temp.match(/.*[0-9].*/) == null)
		{
			alert("Password must contain at least 1 number.");
			check = 1;
			return false;
		}
		if (temp.length < 8) 
		{
			alert("Password length must be at least 8.");
			check = 1;
			return false;
		}
		if (check == 0) {
			return true;
		}

	}
}

function password(pass)
{
	var check = 0;
	if(pass.match(/.*(?=.*?[A-Z]).*/) == null)
	{
		document.querySelector("#passWarning").innerHTML = "Password must contain at least one capital letter";
		check = 1;
	}
	else if (pass.match(/.*(?=.*?[A-Z]).*/) == null)
	{
		document.querySelector("#passWarning").innerHTML = "Password must contain at least one lower-case letter";
		check = 1;
	}
	else if(pass.length < 8)
	{
		document.querySelector("#passWarning").innerHTML = "Password must longer than 8 character";
		check = 1;
	}
}