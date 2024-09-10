

void plot_graph(){

  // Open the CSV data file
    std::ifstream file("hrppd_24_qe_blue_2nd_measure1.csv");
    std::string line;

    // Check if file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return;
    }

    const int n_Y = 125;
    const int n_X = 150;

    double shift_values[n_Y];
    
    TGraph2D *gr1 = new TGraph2D();

    int gr_ind = 0;
    int lineNo = 0;
    while (std::getline(file, line) ) {
      std::istringstream iss(line);
      std::vector<double> rowData;
      std::string value_str;
      
      //cout<<line<<endl;
      
      std::vector<double> values;

      
      
      int y = 0;
      while( iss.good() )
	{
	  string substr;
	  getline( iss, substr, ',' );


	  std::string substr2 = substr.substr(substr.size() - 4);
	  
	  double value = -0.1*std::stod(substr2);
	  
	  if( lineNo == 0 ){
	    shift_values[y] = -100 - value;
	  }

	  value = value + shift_values[y];
	  
	  values.push_back(value);

	  double x = y%2 == 0? lineNo : n_X - 1 - lineNo;

	  gr1->SetPoint(gr_ind, x, y, value);
	  
	  y = y + 1;
	  gr_ind = gr_ind + 1;
	}   
      
      
      lineNo = lineNo + 1;
    }

    //gr1->SetMaximum(-0.024);
    gr1->Draw("colz");
    gr1->SetMarkerColor(4);
    
}
