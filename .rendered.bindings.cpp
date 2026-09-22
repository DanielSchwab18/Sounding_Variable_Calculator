// cppimport


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


        //parcel buoyancy traces
        .def("get_mu_parcel_buoyancy", &Sounding::get_mu_parcel_buoyancy)
        .def("get_ml_parcel_buoyancy", &Sounding::get_ml_parcel_buoyancy)
        .def("get_sb_parcel_buoyancy", &Sounding::get_sb_parcel_buoyancy)
        .def("get_mu_entrainment_parcel_buoyancy", &Sounding::get_mu_entrainment_parcel_buoyancy)
        .def("get_ml_entrainment_parcel_buoyancy", &Sounding::get_ml_entrainment_parcel_buoyancy)
        .def("get_sb_entrainment_parcel_buoyancy", &Sounding::get_sb_entrainment_parcel_buoyancy)

        //parcel temp traces
        .def("get_mu_parcel_temp", &Sounding::get_mu_parcel_temp)
        .def("get_ml_parcel_temp", &Sounding::get_ml_parcel_temp)
        .def("get_sb_parcel_temp", &Sounding::get_sb_parcel_temp)
        .def("get_mu_entrainment_parcel_temp", &Sounding::get_mu_entrainment_parcel_temp)
        .def("get_ml_entrainment_parcel_temp", &Sounding::get_ml_entrainment_parcel_temp)
        .def("get_sb_entrainment_parcel_temp", &Sounding::get_sb_entrainment_parcel_temp)

        //stp
        .def("get_stp", &Sounding::compute_stp)

        //height-variant variables
        .def("get_rh", &Sounding::get_rh)
        .def("get_w", &Sounding::get_w)
        .def("get_srw", &Sounding::get_srw)
        .def("get_srh", &Sounding::get_srh)
        .def("get_shear", &Sounding::get_shear)
        .def("get_streamwise_vorticity", &Sounding::get_streamwise_vorticity)

        //capes
        .def("get_sbcape", &Sounding::get_sbcape)
        .def("get_mlcape", &Sounding::get_mlcape)
        .def("get_mucape", &Sounding::get_mucape)
        .def("get_sbecape", &Sounding::get_sbecape)
        .def("get_mlecape", &Sounding::get_mlecape)
        .def("get_muecape", &Sounding::get_muecape);
}