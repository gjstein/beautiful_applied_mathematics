#include "gnuplot.h"

void gnuplot(std::vector<double> y)
{

  FILE *gnuplot_pipe;
  gnuplot_pipe = popen(GNUPLOT,"w");

  // Handle broken pipe
  if ( gnuplot_pipe == NULL )
  {
    printf("Could not open pipe; ensure gnuplot is in the path.");
    return;
  }

  //  fprintf(gnuplot_pipe,"set term png\n set output \"fun.png\" \n");
  fprintf(gnuplot_pipe,"set term dumb");
  fprintf(gnuplot_pipe,"set samples 2000 \n");
  fprintf(gnuplot_pipe,"plot cos(x) \n");
  fprintf(gnuplot_pipe,"rep sin(x) \n");
  fclose(gnuplot_pipe);

}
