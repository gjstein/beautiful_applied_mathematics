#include <sys/stat.h>
#include <string>
#include <unistd.h>
#include "gtest/gtest.h"

#include "gnuplot.h"

// Existance of file
inline bool file_exists(const std::string& name)
{
  struct stat buffer;
  return ( stat(name.c_str(), &buffer) == 0 );
}


TEST(GnuplotTest, testPiping)
{

  // == Create Example Figure (png) == //
  // .png file name
  std::string name("test_piping.png");

  // Check file does not exist
  if ( file_exists(name) )
    remove( name.c_str() );
  ASSERT_FALSE(file_exists(name));

  FILE *gnuplot_pipe;
  gnuplot_pipe = popen(GNUPLOT,"w");

  // Handle broken pipe
  if ( gnuplot_pipe == NULL )
  {
    printf("Could not open pipe; ensure gnuplot is in the path.");
    // TODO Add failure mode here
    return;
  }

  fprintf(gnuplot_pipe,"set term png\n set output \"%s\" \n",name.c_str());
  fprintf(gnuplot_pipe,"set samples 2000 \n");
  fprintf(gnuplot_pipe,"plot cos(x) \n");
  fclose(gnuplot_pipe);

  // Check png exists (loop required; gnuplot can be slow)
  int counter = 0;
  while (!file_exists(name) && counter++<100){ usleep(1000); }
  
  // Check file exists
  ASSERT_TRUE(file_exists(name));
  
  // Delete file & check that it's deleted
  remove( name.c_str() );
  ASSERT_FALSE(file_exists(name));
  
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
