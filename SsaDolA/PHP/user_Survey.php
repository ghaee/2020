<?php
header('Content-Type: text/html; charset=UTF-8');

putenv("LANG=ko_KR.UTF-8");
setlocale(LC_ALL, 'ko_KR.utf8');
//POST 값을 읽어온다.
$Q1=isset($_POST['Q1']) ? $_POST['Q1'] : ''; 
$Q2=isset($_POST['Q2']) ? $_POST['Q2'] : ''; 
$Q3=isset($_POST['Q3']) ? $_POST['Q3'] : ''; 
$Q4=isset($_POST['Q4']) ? $_POST['Q4'] : ''; 
$Q5=isset($_POST['Q5']) ? $_POST['Q5'] : ''; 
$Q6=isset($_POST['Q6']) ? $_POST['Q6'] : ''; 
$Q7=isset($_POST['Q7']) ? $_POST['Q7'] : ''; 
$Q8=isset($_POST['Q8']) ? $_POST['Q8'] : ''; 



if ($Q1 !="" and $Q2 !="" and $Q3 !="" and $Q4 !="" and $Q5 !=""){   
  
  $command = "sudo /usr/bin/python3 ../python/test.py '$Q1' '$Q2' '$Q3' '$Q4' '$Q5' '$Q6' '$Q7' '$Q8'";
  exec($command,$out,$result);
  print_r($out);
 
} else {
    echo "데이터를 입력하세요 ";
}
mysqli_close($con);

?>
<?php

$android = strpos($_SERVER['HTTP_USER_AGENT'], "Android");

if (!$android){
?>

<html>
   <body>
   
      <form action="<?php $_PHP_SELF ?>" method="POST">
         Q1: <input type = "text" name = "Q1" />
         Q2: <input type = "text" name = "Q2" />
         Q3: <input type = "text" name = "Q3" />
         Q4: <input type = "text" name = "Q4" />
         Q5: <input type = "text" name = "Q5" />
         Q6: <input type = "text" name = "Q6" />
         Q7: <input type = "text" name = "Q7" />
         Q8: <input type = "text" name = "Q8" />
         <input type = "submit" />
      </form>
   
   </body>
</html>
<?php
}
   
?>