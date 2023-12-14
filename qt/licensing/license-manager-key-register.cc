#include "license-manager-key-register.h"

using namespace licensepp;

// generate your won using ripe:
//      ripe -g --aes --length 128 | sed -E 's/(..)/0x\1, /g' | tr -d '\n' | sed 's/, $//'
//
const std::array<unsigned char, 16> LicenseManagerKeyRegister::LICENSE_MANAGER_SIGNATURE_KEY = {
    0x9B, 0x33, 0x3B, 0x8D, 0x88, 0x6E, 0x39, 0xCA, 0x74, 0x8A, 0x20, 0x07, 0x5D, 0x69, 0xB9, 0x91
};

const std::vector<IssuingAuthority> LicenseManagerKeyRegister::LICENSE_ISSUING_AUTHORITIES = {
    IssuingAuthority(
        // authority ID
        "firewebkit-licensing",
        // authority name
        "Firewebkit Legal Team",
        // generate your own using ripe:
        //     ripe -g --rsa --length 2048
        //
        "LS0tLS1CRUdJTiBSU0EgUFJJVkFURSBLRVktLS0tLQpNSUlFb1FJQkFBS0NBUUVBbVE3OHJuaDd2MmtRdEJINGxTQXFubDJDR0x3TmtNNi9kUFpIMkRpbHg1MWl1b0pRCjRUTEYzTVFsc0ZkcXIwOE4xQ0lhbDYxOTd3MFhsSDdRby96THFNemY1WkE0bjFMN3Z0RjR5VHNmTDdIdU5ENjIKUitkVmFuZ0IwQm9DbTBIS1FDd1JMdFJ6aE9PYTRoSjZXdFBuZzU4M3NFekVJL1hiY2RIeTl1a1JpMHhuRy9jYQpNUFdsTVVQdWFwVGhaK2JWdXgvR1VrUFdmR2JiQnlGMkFKQjRGeXJOS1NBMlljWUdrTTROK29lZS9DQWpLOGFGCmxLOTduSTRxQ2p6bXVqUFN0NTVRZW82enFqVHUvUjlSekVkNWV5M0llQ0szeTF4dDNNWkdyZUV1M3RDYTJPSysKek5oWHJWYTJQQ3cvVjVYRlRqRTVMdERpL0QxZG12OUJ1Q3paZlFJQkVRS0NBUUFIZ0x3U2wzbUVYUDVQR2ZxZAo1ZmdNeUZremFKZEEwdXRFZW9FREVkWHVMVnl1eWljYUdSTzlCSmh2aTlDR0ZYR2VlaVJ3Mk5GM284ZHVMbCtQCmtXbGJHUm9JdmtrTTFHR3NmYmdkOFZSYUxsNkFEUjBEaGxIOXNJeWpUSkd5UnYxZGY2WjlScVpLUjJSMGZtVmUKemliMDRpaGdmRHZQa1JKSldCaDFnK1ZBamJWb1czcGRSNkdiVlVKQWZvZEtEWktJb0RIdEs2SEM2bSt5ditVYwpXMnVONlpOV0Y0SlMrZTVQbXY1MHVBSUpnSXdSby9LWFFORUdCdHZ4QnVRZnRjSWc5K3J2WDk4bG1mK01wY0IrCjZqemRDV2VuamhwR1YrYUx5S0VSREZwSENMcmxIVUhHd0RXdm13SGZBSk9BZVZiV2c4aERPczBlaWtzcW9GcHUKSmpMakFvR0JBTUdQZlFxdEl1dXRrV0UzckpMaTRGa3dSUGlHQzJOOWpPMk9hNUU5TTY4UWR4UTh5SUM5NUx4Zwp6Z0duckI0OVVzalEzMEkyZUVtZVdqK0tYekJkWVBPU2h6QWZxaHNCck5lazY5ZEZGVkk4RWluQ2xsajVLUGxLClFTL3V6NEg5VjZkSEJtVlFLcXBHeWc4SVVhNmxKMVJuTVhpMjZiVGs4SkM5NStFMU5VUmpBb0dCQU1wdXlZSjcKVUtXSlRhd1BPWWFlV0FKMGZUbXl2bHZjK0RvSEJOWWFlamJxNDVUYzNvWTZYUmx4cGl2U21DUDg5V1FtUFNHMwpEUEJRRG1PeFVTSThWd0NFaU00VWRBT3BkYm9pL2lPZFZJRFZLSTliYkswM01raWlJZHFXZkJUUitnN3BoNElNCmo4eWJaYlE3YUdsQ1hMaWJzcGZwTjZKMUZHa1JIUGlJdVNDZkFvR0FJaWhoWER5cnp6eS9UV1F0ZzFVMnBsUFAKNzU4dkw2eStoRVpQTjcrQmwxMUNNTDl1clU2djVRSUdQSWNBUVpKWjV6UHJLYzFnaFhaTUtWU25ZdU5OV0NqcQpyaU8wbTFxbUIrL3RZamxlSFpJaFVxbmVTKys3NzhIUFJMR3NKZitIOEZmVDg4TGFXa2k2UHVOWnRXaHdXakJVCkJqNWxla2FFemoraFkvcFVzYmNDZ1lFQWp1VEtlamp0b2dhUkxpamRUL2ROTHVqUTNXOGM5WXpyZEVFd2x5Ry8Kcmt0emVDTnY1a2RReHFxVGFqcE5ScFJ3KzJaSlJQbXV4OEFLS0VEdCtneDVwZ016WkVxc1B0SDR2NkE2Ni9hVwpBSloyKzhnUWVrVVViNEdCVHdEUURySldLS1RZSDVCbGdWNmlKTjZrRGhDNTY3a3l4WldRcnVrN2xYVjkzSnkrCjZka0NnWUJQZGI2YkpEaUdpUVVvRW9EcGhuejlSYUlKLzV3VEdWVm5mbG12MWJlbzJId1BqeTBPTmxET3gyclQKMlNZeERsS29QOUNZT0hyN2xVZVVrK2FoQVFvcHY0OVJyOGs0YndaZXBrTkpYYm9mVmJ4UFhrZkdPMjVSUkRBNgozbk5UMHFDQ085Njg5ZXFsTlMvY01zemxoVm9kcWxJdHZ4dUhWQ2FERGducDBDSGlMdz09Ci0tLS0tRU5EIFJTQSBQUklWQVRFIEtFWS0tLS0tCg==:LS0tLS1CRUdJTiBQVUJMSUMgS0VZLS0tLS0KTUlJQklEQU5CZ2txaGtpRzl3MEJBUUVGQUFPQ0FRMEFNSUlCQ0FLQ0FRRUFtUTc4cm5oN3Yya1F0Qkg0bFNBcQpubDJDR0x3TmtNNi9kUFpIMkRpbHg1MWl1b0pRNFRMRjNNUWxzRmRxcjA4TjFDSWFsNjE5N3cwWGxIN1FvL3pMCnFNemY1WkE0bjFMN3Z0RjR5VHNmTDdIdU5ENjJSK2RWYW5nQjBCb0NtMEhLUUN3Ukx0UnpoT09hNGhKNld0UG4KZzU4M3NFekVJL1hiY2RIeTl1a1JpMHhuRy9jYU1QV2xNVVB1YXBUaForYlZ1eC9HVWtQV2ZHYmJCeUYyQUpCNApGeXJOS1NBMlljWUdrTTROK29lZS9DQWpLOGFGbEs5N25JNHFDanptdWpQU3Q1NVFlbzZ6cWpUdS9SOVJ6RWQ1CmV5M0llQ0szeTF4dDNNWkdyZUV1M3RDYTJPSyt6TmhYclZhMlBDdy9WNVhGVGpFNUx0RGkvRDFkbXY5QnVDeloKZlFJQkVRPT0KLS0tLS1FTkQgUFVCTElDIEtFWS0tLS0tCg==",
        87600U, // 10 years max
        true
    ),
};
