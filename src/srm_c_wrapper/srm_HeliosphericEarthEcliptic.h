
#ifndef __SRM_HELIOSPHERICEARTHECLIPTIC_H_INCLUDED__
#define __SRM_HELIOSPHERICEARTHECLIPTIC_H_INCLUDED__

#include "srm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    SRM_ChangeCoordinate3DArraySRF       *ChangeCoordinate3DArraySRF;
    SRM_ChangeCoordinate3DArraySRFObject *ChangeCoordinate3DArraySRFObject;
    SRM_ChangeCoordinate3DSRF            *ChangeCoordinate3DSRF;
    SRM_ChangeCoordinate3DSRFObject      *ChangeCoordinate3DSRFObject;
    SRM_ChangeDirectionArraySRF          *ChangeDirectionArraySRF;
    SRM_ChangeDirectionArraySRFObject    *ChangeDirectionArraySRFObject;
    SRM_ChangeDirectionSRF               *ChangeDirectionSRF;
    SRM_ChangeOrientationSRF             *ChangeOrientationSRF;
    SRM_ChangeDirectionSRFObject         *ChangeDirectionSRFObject;
    SRM_ChangeOrientationSRFObject       *ChangeOrientationSRFObject;
    SRM_CreateCoordinate3D               *CreateCoordinate3D;
    SRM_CreateDirection                  *CreateDirection;
    SRM_CreateOrientation                *CreateOrientation;
    SRM_Destroy                          *Destroy;
    SRM_DestroyCoordinate3D              *DestroyCoordinate3D;
    SRM_DestroyDirection                 *DestroyDirection;
    SRM_DestroyOrientation               *DestroyOrientation;
    SRM_EuclideanDistance3D              *EuclideanDistance3D;
    SRM_GetCoordinate3DValues            *GetCoordinate3DValues;
    SRM_GetCSCode                        *GetCSCode;
    SRM_GetA                             *GetA;
    SRM_GetF                             *GetF;
    SRM_GetDirectionValues               *GetDirectionValues;
    SRM_GetNaturalSRFSMemberCode         *GetNaturalSRFSMemberCode;
    SRM_GetOrientationValues             *GetOrientationValues;
    SRM_GetExtendedValidRegion           *GetExtendedValidRegion;
    SRM_GetORMCodes                      *GetORMCodes;
    SRM_GetSRFCodes                      *GetSRFCodes;
    SRM_GetValidRegion                   *GetValidRegion;
    SRM_SetCoordinate3DValues            *SetCoordinate3DValues;
    SRM_SetExtendedValidRegion           *SetExtendedValidRegion;
    SRM_SetValidRegion                   *SetValidRegion;
} SRM_HEEC_Method_List;

/** This is the struct for the Heliospheric Earth Ecliptic SRF.
    @param state in: this SRF state
    @param methods in: this SRF methods list
*/
typedef struct
{
    void                 *state;
    SRM_HEEC_Method_List *methods;
} SRM_HeliosphericEarthEcliptic;


/** This creates a new Heliospheric Earth Ecliptic SRF.
    @param orm_code in: this object reference model
    @param rt_code in: this reference transformation
    @param new_srf out: results in a new SRF
    @returns a status code
*/
extern SRM_Status_Code
SRM_HEEC_Create
(
    SRM_ORM_Code                   orm_code,
    SRM_RT_Code                    rt_code,
    SRM_HeliosphericEarthEcliptic *new_srf /* OUT */
);

#ifdef __cplusplus
}
#endif
#endif
