#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include <ableton/Link.hpp>

namespace py = pybind11;

PYBIND11_MODULE(abletonlink, m)
{
    py::class_<ableton::Link>(m, "Link")
        .def(py::init<double>())
        .def("isEnabled", &ableton::Link::isEnabled)
        .def("enable", &ableton::Link::enable)
        .def("isStartStopSyncEnabled", &ableton::Link::isStartStopSyncEnabled)
        .def("enableStartStopSync", &ableton::Link::enableStartStopSync)
        .def("numPeers", &ableton::Link::numPeers)
        // TODO in order to expose the callback, the deadlock occuring when Link is deleted should be fixed
        // .def("setNumPeersCallback", &ableton::Link::setNumPeersCallback<std::function<void(std::size_t)>>)
        // .def("setTempoCallback", &ableton::Link::setTempoCallback<std::function<void(double)>>)
        // .def("setStartStopCallback", &ableton::Link::setStartStopCallback<std::function<void(bool)>>)
        .def("clock", &ableton::Link::clock)
        .def("captureAudioSessionState", &ableton::Link::captureAudioSessionState)
        .def("commitAudioSessionState", &ableton::Link::commitAudioSessionState)
        .def("captureAppSessionState", &ableton::Link::captureAppSessionState)
        .def("commitAppSessionState", &ableton::Link::commitAppSessionState);

    py::class_<ableton::Link::SessionState>(m, "SessionState")
        .def("tempo", &ableton::Link::SessionState::tempo)
        .def("setTempo", &ableton::Link::SessionState::setTempo)
        .def("beatAtTime", &ableton::Link::SessionState::beatAtTime)
        .def("phaseAtTime", &ableton::Link::SessionState::phaseAtTime)
        .def("timeAtBeat", &ableton::Link::SessionState::timeAtBeat)
        .def("requestBeatAtTime", &ableton::Link::SessionState::requestBeatAtTime)
        .def("forceBeatAtTime", &ableton::Link::SessionState::forceBeatAtTime)
        .def("setIsPlaying", &ableton::Link::SessionState::setIsPlaying)
        .def("isPlaying", &ableton::Link::SessionState::isPlaying)
        .def("timeForIsPlaying", &ableton::Link::SessionState::timeForIsPlaying)
        .def("requestBeatAtStartPlayingTime", &ableton::Link::SessionState::requestBeatAtStartPlayingTime)
        .def("setIsPlayingAndRequestBeatAtTime", &ableton::Link::SessionState::setIsPlayingAndRequestBeatAtTime);

    py::class_<ableton::Link::Clock>(m, "Clock")
        .def("micros", &ableton::Link::Clock::micros);
}
