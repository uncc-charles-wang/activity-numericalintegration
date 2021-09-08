#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif
using namespace std::chrono;

float get_function_value(int f,int x, int intensity) {
    switch(f) {
      case 1:
          return f1(x, intensity);
          break;
      case 2:
          return f2(x, intensity);
          break;
      case 3:
          return f3(x, intensity);
          break;
      case 4:
          return f4(x, intensity);
          break;
  }
  
  std::cout << "Error: f is not valid.\n";
  return 0.0f;
}
  
int main (int argc, char* argv[]) {

  if (argc < 6) {
    std::cerr<<"usage: "<<argv[0]<<" <functionid> <a> <b> <n> <intensity>"<<std::endl;
    return -1;
  }
  
  int fuctionID  = atoi(argv[1]);
  int lowerBound = atoi(argv[2]); // This is a
  int upperBound = atoi(argv[3]); // This is b
  int n          = atoi(argv[4]);
  int intensity  = atoi(argv[5]);
  
  auto startTime = system_clock::now();
  
  int result = 0;
  float start = (upperBound - lowerBound) / static_cast<float>(n);
  
  //std::cout << start << std::endl;
  
  float temp = 0.0f;
  
  for(int i = 0; i < n; i++) {
    int x_value = static_cast<float>(lowerBound + (i + 0.5f) * start);
    temp += get_function_value(fuctionID, x_value, intensity);
  }
  
  std::cout << temp;
  result = start * temp;
  std::cout << result;
  
  auto stopTime = system_clock::now();
  
  std::chrono::duration<double> diff = stopTime - startTime;
  
  
  std::cerr << diff.count();
  
  return 0;
}
