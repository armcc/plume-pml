/*
Copyright (c) 2015, Plume Design Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
   3. Neither the name of the Plume Design Inc. nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Plume Design Inc. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef STATSSIM_H_INCLUDED
#define STATSSIM_H_INCLUDED

#include "dppline.h"

#define RADIO_MAX_DEVICE_QTY            2

/*
 * Simulated stats generator API
 */
typedef struct sim_ap_conf
{
    char nodeid[32];
    struct
    {
        int  n_client;
        char **client;
        int  n_neigh;
        char **neigh;
        int  n_surv;
        char **surv;
        int  n_cap;
        char **cap;
        int  n_rssi;
        char **rssi;
    } r[2];
} sim_ap_conf_t;

extern sim_ap_conf_t *sim_ap_conf;

void getSurveyReport(dpp_survey_report_data_t *r, radio_type_t radio_type, radio_scan_type_t s_type);
void getNeighborReport(dpp_neighbor_report_data_t *r, radio_type_t radio_type);
void getClientReport(dpp_client_report_data_t *r, radio_type_t radio_type);
void getDeviceReport(dpp_device_report_data_t *r);
void getCapacityReport(dpp_capacity_report_data_t *r, radio_type_t radio_type);
void getBSClientReport(dpp_bs_client_report_data_t *r);
void getRssiReport(dpp_rssi_report_data_t *r, radio_type_t radio_type);

#endif /* STATSSIM_H_INCLUDED */
