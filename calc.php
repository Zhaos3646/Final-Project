<!DOCTYPE html>
<html>
  <head>
    <title> Calculate </title>
  </head>


  <body>

    <h1>Area of Circle</h1>
    <p>Enter the minimum and maximum interval of circle radius values</p>

    <?php
       // define variables and set to empty values
       $arg1 = $output = $retc = "";
       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         exec("/usr/lib/cgi-bin/sp1a/calculate " . $arg1 . " " . , $output, $retc); 
       }
       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Arg1: <input type="text" name="arg1"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
         echo "<h2>Program Output:</h2>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
    ?>
  </body>
</html>
