#include <vector>
#include <iostream>

#ifndef INCLUDE_LINALG_IO_HH_
#define INCLUDE_LINALG_IO_HH_
namespace linalg_io {

typedef std::vector<std::vector<std::vector<std::vector<std::vector<double> > > > > corrmat_data;

//read confs*Rs*Ts dim dimensional correlation matrices from data_ifs into 5-dim vector.
//data should have confs blocks of Rs blocks of Ts dim dimensional matrices.
//matrix elements are read one per line in order M_11 M_12 ... M_1dim M_21 .. M_2dim ... M_dim1 .. M_dimdim
//access like [config][R][T][operator1][operator2]
corrmat_data read_correlation_matrices(std::istream& data, const int dim, const int Rs, const int Ts, const int confs);

//write matrices given by 5-dim vector to output_file_ofs (no formatting, set up the stream beforehand).
//data is written in blocks starting from the toplevel vector.
//an empty line is written after the end of each block except for the innermost vector.
void write_correlation_matrices(std::ostream& output_file, corrmat_data& cms);

}

#endif /* INCLUDE_LINALG_IO_HH_ */
