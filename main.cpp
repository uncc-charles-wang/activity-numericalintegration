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
  
  float result = 0.0f;
  float start = (upperBound - lowerBound) / static_cast<float>(n);
  float temp = 0.0f;
  
  for(int i = 0; i < n; i++) {
    temp += get_function_value(fuctionID, 
                               lowerBound + (i + 0.5f ) * start,
                               intensity);
  }
  
  result = start * temp;
  
  auto stopTime = system_clock::now();
  
  std::chrono::duration<double> diff = stopTime - startTime;
  
  std::cout << result;
  std::cerr << diff.count();
  
  return 0;
}
