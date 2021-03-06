
#ifndef __SRM_LOCALSPACEAZIMUTHAL_H_INCLUDED__
#define __SRM_LOCALSPACEAZIMUTHAL_H_INCLUDED__

#include "srm.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    SRM_ChangeCoordinate2DArraySRF       *ChangeCoordinate2DArraySRF;
    SRM_ChangeCoordinate2DArraySRFObject *ChangeCoordinate2DArraySRFObject;
    SRM_ChangeCoordinate2DSRF            *ChangeCoordinate2DSRF;
    SRM_ChangeCoordinate2DSRFObject      *ChangeCoordinate2DSRFObject;
    SRM_CreateCoordinate2D               *CreateCoordinate2D;
    SRM_Destroy                          *Destroy;
    SRM_DestroyCoordinate2D              *DestroyCoordinate2D;
    SRM_EuclideanDistance2D              *EuclideanDistance2D;
    SRM_GetCoordinate2DValues            *GetCoordinate2DValues;
    SRM_GetCSCode                        *GetCSCode;
    SRM_GetORMCodes                      *GetORMCodes;
    SRM_GetSRFCodes                      *GetSRFCodes;
    SRM_SetCoordinate2DValues            *SetCoordinate2DValues;
} SRM_LSA_Method_List;


/** This is the struct for the Local Space Azimuthal SRF.
    @param state in: this SRF state
    @param methods in: this SRF methods list
*/
typedef struct
{
    void                *state;
    SRM_LSA_Method_List *methods;
} SRM_LocalSpaceAzimuthal;

/** This creates a new Local Space Azimuthal SRF.
    @param orm_code in: this object reference model
    @param rt_code in: this reference transformation
    @param new_srf out: results in a new SRF
    @returns a status code
*/
extern SRM_Status_Code
SRM_LSA_Create
(
    SRM_ORM_Code             orm_code,
    SRM_RT_Code              rt_code,
    SRM_LocalSpaceAzimuthal *new_srf /* OUT */
);

#ifdef __cplusplus
}
#endif
#endif
