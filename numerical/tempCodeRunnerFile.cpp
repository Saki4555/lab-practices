  double error = exact - integral;
  cout << "Error = " << error << endl;
  

  double relative_error = (error/exact)*100;
  cout << "Relative error percentage = " << relative_error << endl;
  