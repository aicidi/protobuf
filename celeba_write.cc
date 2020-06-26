#include <iostream>
#include <fstream>
#include <string>
#include "csv.h"
#include "celeba.pb.h"

void AddBboxData(celeba::Bbox* bbox, std::string& image_id, int x_1, int y_1, int width, int height) {
  bbox->set_image_id(image_id);
  bbox->set_x_1(x_1);
  bbox->set_y_1(y_1);
  bbox->set_width(width);
  bbox->set_height(height);
}

int main(int argc, char* argv[]) {
  using std::ios;
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  io::CSVReader<5> in("../list_bbox_celeba.csv");
  in.read_header(io::ignore_extra_column, "image_id", "x_1", "y_1", "width", "height");
  
  std::string image_id; 
  int x_1, y_1, width, height;
  
  celeba::Data csv_data;
  
  while(in.read_row(image_id, x_1, y_1, width, height)){
    AddBboxData(csv_data.add_bbox(), image_id, x_1, y_1, width, height);
  }
  
  {
    // Write the new address book back to disk.
    std::fstream output("list_bbox_celeba.bin", ios::out | ios::trunc | ios::binary);
    if (!csv_data.SerializeToOstream(&output)) {
      std::cerr << "Failed to write bbox csv." << std::endl;
      return -1;
    }
  }
  
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}