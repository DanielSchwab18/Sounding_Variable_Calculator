// cppimport
<%
import pybind11
cfg['include_dirs'] = ['include', pybind11.get_include()]
cfg['compiler_args'] = ['/std:c++latest']
%>

#include <cstring>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "include/Sounding.hpp"

namespace py = pybind11;

PYBIND11_MODULE(bindings, m) {
    py::class_<Sounding>(m, "Sounding")
        .def(py::init<std::string, bool, bool, int>(),
             py::arg("sounding_file_name"),
             py::arg("needs_interpolation"),
             py::arg("interpolate_cape"),
             py::arg("resolution"))

        // height-layer averages
        .def("get_rh", &Sounding::get_rh)
        .def("get_w", &Sounding::get_w)
        .def("get_srw", &Sounding::get_srw)
        .def("get_srh", &Sounding::get_srh)
        .def("get_streamwise_vorticity", &Sounding::get_streamwise_vorticity)
        .def("get_shear", &Sounding::get_shear)

        // fractional entrainment
        .def("get_sb_fractional_entrainment", &Sounding::get_sb_fractional_entrainment)
        .def("get_ml_fractional_entrainment", &Sounding::get_ml_fractional_entrainment)
        .def("get_mu_fractional_entrainment", &Sounding::get_mu_fractional_entrainment)

        // CAPE / ECAPE (3-parcel variants)
        .def("get_sb3cape", &Sounding::get_sb3cape)
        .def("get_sb3ecape", &Sounding::get_sb3ecape)
        .def("get_ml3cape", &Sounding::get_ml3cape)
        .def("get_ml3ecape", &Sounding::get_ml3ecape)
        .def("get_mu3cape", &Sounding::get_mu3cape)
        .def("get_mu3ecape", &Sounding::get_mu3ecape)

        // e_a tilde
        .def("get_sb_e_a_tilde", &Sounding::get_sb_e_a_tilde)
        .def("get_ml_e_a_tilde", &Sounding::get_ml_e_a_tilde)
        .def("get_mu_e_a_tilde", &Sounding::get_mu_e_a_tilde)

        // bunkers motion
        .def("get_bunkers_u", &Sounding::get_bunkers_u)
        .def("get_bunkers_v", &Sounding::get_bunkers_v)

        // buoyancy at a height
        .def("get_sb_B_at_height", &Sounding::get_sb_B_at_height)
        .def("get_ml_B_at_height", &Sounding::get_ml_B_at_height)
        .def("get_mu_B_at_height", &Sounding::get_mu_B_at_height)
        .def("get_sb_EB_at_height", &Sounding::get_sb_EB_at_height)
        .def("get_ml_EB_at_height", &Sounding::get_ml_EB_at_height)
        .def("get_mu_EB_at_height", &Sounding::get_mu_EB_at_height)

        // buoyancy integrated to a height
        .def("get_sb_B_to_height", &Sounding::get_sb_B_to_height)
        .def("get_ml_B_to_height", &Sounding::get_ml_B_to_height)
        .def("get_mu_B_to_height", &Sounding::get_mu_B_to_height)
        .def("get_sb_EB_to_height", &Sounding::get_sb_EB_to_height)
        .def("get_ml_EB_to_height", &Sounding::get_ml_EB_to_height)
        .def("get_mu_EB_to_height", &Sounding::get_mu_EB_to_height)

        // CIN / ECIN
        .def("get_sb_lcin", &Sounding::get_sb_lcin)
        .def("get_sb_lecin", &Sounding::get_sb_lecin)
        .def("get_ml_lcin", &Sounding::get_ml_lcin)
        .def("get_ml_lecin", &Sounding::get_ml_lecin)
        .def("get_mu_lcin", &Sounding::get_mu_lcin)
        .def("get_mu_lecin", &Sounding::get_mu_lecin)

        // misc profile info
        .def("get_ml_top", &Sounding::get_ml_top)
        .def("get_size", &Sounding::get_size)
        .def("get_ml_lfc_p", &Sounding::get_ml_lfc_p)
        .def("get_ml_e_lfc_p", &Sounding::get_ml_e_lfc_p)

        // LCL / e-LCL heights
        .def("get_sb_lcl", &Sounding::get_sb_lcl)
        .def("get_ml_lcl", &Sounding::get_ml_lcl)
        .def("get_mu_lcl", &Sounding::get_mu_lcl)
        .def("get_sb_e_lcl", &Sounding::get_sb_e_lcl)
        .def("get_ml_e_lcl", &Sounding::get_ml_e_lcl)
        .def("get_mu_e_lcl", &Sounding::get_mu_e_lcl)

        // nearest LCL / e-LCL height index
        .def("get_nearest_sb_lcl_height", &Sounding::get_nearest_sb_lcl_height)
        .def("get_nearest_ml_lcl_height", &Sounding::get_nearest_ml_lcl_height)
        .def("get_nearest_mu_lcl_height", &Sounding::get_nearest_mu_lcl_height)
        .def("get_nearest_sb_e_lcl_height", &Sounding::get_nearest_sb_e_lcl_height)
        .def("get_nearest_ml_e_lcl_height", &Sounding::get_nearest_ml_e_lcl_height)
        .def("get_nearest_mu_e_lcl_height", &Sounding::get_nearest_mu_e_lcl_height)

        //parcel buoyancy traces
        .def("get_mu_parcel_buoyancy", &Sounding::get_mu_parcel_buoyancy)
        .def("get_ml_parcel_buoyancy", &Sounding::get_ml_parcel_buoyancy)
        .def("get_sb_parcel_buoyancy", &Sounding::get_sb_parcel_buoyancy)
        .def("get_mu_entrainment_parcel_buoyancy", &Sounding::get_mu_entrainment_parcel_buoyancy)
        .def("get_ml_entrainment_parcel_buoyancy", &Sounding::get_ml_entrainment_parcel_buoyancy)
        .def("get_sb_entrainment_parcel_buoyancy", &Sounding::get_sb_entrainment_parcel_buoyancy)

        // composite index
        .def("compute_stp", &Sounding::compute_stp);
}