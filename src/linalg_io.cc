#include <linalg_io.hh>
#include <vector>
#include <fstream>

namespace linalg_io {

corrmat_data read_correlation_matrices(std::istream& data, const int dim, const int Rs, const int Ts,
		const int confs) {
	std::vector<std::vector<std::vector<std::vector<std::vector<double> > > > > cms(confs,
			std::vector<std::vector<std::vector<std::vector<double> > > >(Rs,
					std::vector<std::vector<std::vector<double> > >(Ts,
							std::vector<std::vector<double> >(dim,
									std::vector<double>(dim, 0.0)))));
	for (int config = 0; config < confs; ++config)
		for (int R = 0; R < Rs; ++R)
			for (int T = 0; T < Ts; ++T)
				for (int o1 = 0; o1 < dim; ++o1)
					for (int o2 = 0; o2 < dim; ++o2)
						data >> cms[config][R][T][o1][o2];
	return cms;
}

void write_correlation_matrices(std::ostream& os, corrmat_data& cmd) {
	for (int config = 0; config < cmd.size(); ++config) {
		for (int R = 0; R < cmd[0].size(); ++R) {
			for (int T = 0; T < cmd[0][0].size(); ++T) {
				for (int o1 = 0; o1 < cmd[0][0][0].size(); ++o1) {
					for (int o2 = 0; o2 < cmd[0][0][0][0].size(); ++o2) {
						os << cmd[config][R][T][o1][o2] << "\n";
					}
				}
				os << "\n";
			}
			os << "\n";
		}
		os << "\n";
	}
}

}
