<?php
  include 'connect.php';

  if(isset($_POST['submit'])){
    $name = $_POST['name'];
    $email = $_POST['email'];
    $mobile = $_POST['mobile'];
    $passowrd =$_POST['password'];

    $sql ="insert into `crud` (name, email, mobile, password)
    values('$name', '$email', '$mobile', '$passowrd')";

    $result = mysqli_query($con, $sql);
    if($result){
      // echo "data inserted sucessfully";
      header('location:display.php');
    }
    else{
      die(mysqli_error($con));
    }

    $con->close();
  }
?>

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Bootstrap demo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-aFq/bzH65dt+w6FI2ooMVUpc+21e0SRygnTpmBvdBgSdnuTN7QbdgL+OapgHtvPp" crossorigin="anonymous">
  </head>
  <body>
    <h1>Crud Operation</h1>

    <div class="container">
    <form method = "post">
    <input type="text" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="name" name="name" autocomplete="off">

    <input type="email" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="email" name="email" autocomplete="off">

    <input type="text" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="mobile" name="mobile" autocomplete="off">

    <input type="password" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="password" name="password" autocomplete="off">

    <button class="btn btn-primary" name="submit">submit</button>
    
</form>
    </div>



    <script>
      if ( window.history.replaceState ) {
  window.history.replaceState( null, null, window.location.href );
}
    </script>
    <!-- bs js -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha2/dist/js/bootstrap.bundle.min.js" integrity="sha384-qKXV1j0HvMUeCBQ+QVp7JcfGl760yU08IQ+GpUo5hlbpg51QRiuqHAJz8+BrxE/N" crossorigin="anonymous"></script>
  </body>
</html>