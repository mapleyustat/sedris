
#ifndef _SE_DRM_4P0_H_INCLUDED
#define _SE_DRM_4P0_H_INCLUDED

//
// DESCRIPTION:
//   This file is for internal use only; SEDRIS users should not include
//   this file. See drm.h for the file that SEDRIS users should include.
//

#ifdef __cplusplus
extern "C" {
#endif

#include "drm_types.h"
#include "drm_types_4p0.h"

/*
 * GLOBAL VARIABLE: SE_4p0_IsA
 *
 *   See SE_IsA[][] for description.
 */
extern const SE_Boolean
SE_4p0_IsA[SE_4P0_NUM_DRM_CLASSES][SE_4P0_NUM_DRM_CLASSES];


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_ClassCount
 *
 *   See SE_GeneralClassCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_ClassCount
(
    SE_Short_Integer_Positive *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_DRMClassStringToDRMClass
 *
 *   See SE_GeneralDRMClassStringToDRMClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_DRMClassStringToDRMClass
(
    const char          *name_ptr,
          SE_4p0_DRM_Class *drm_class_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_EnumerantName
 *
 *   See SE_GeneralEnumerantName() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_EnumerantName
(
          SE_4p0_DRM_Type           drm_type,
          SE_Integer   value,
    const char       **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_FieldCountForClass
 *
 *   See SE_GeneralFieldCountForClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_FieldCountForClass
(
    SE_4p0_DRM_Class drm_class,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_FieldCountForType
 *
 *   See SE_GeneralFieldCountForType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_FieldCountForType
(
    SE_4p0_DRM_Type drm_type,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_FieldIndexForClass
 *
 *   See SE_GeneralFieldIndexForClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_FieldIndexForClass
(
          SE_4p0_DRM_Class drm_class,
    const char                      *mem_name_ptr,
          SE_Short_Integer_Unsigned *index_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetAggregateOfType
 *
 *   See SE_GeneralGetAggregateOfType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_GetAggregateOfType
(
          SE_4p0_DRM_Class drm_class_a,
          SE_4p0_DRM_Class drm_class_b,
    const SE_Requirement **req_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetAssociateOfType
 *
 *   See SE_GeneralGetAssociateOfType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_GetAssociateOfType
(
          SE_4p0_DRM_Class drm_class_a,
          SE_4p0_DRM_Class drm_class_b,
    const SE_Requirement **req_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetClassStructure
 *
 *   See SE_GeneralGetClassStructure() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_GetClassStructure
(
          SE_4p0_DRM_Class drm_class,
    const SE_Class_Structure **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetComponentOfType
 *
 *   See SE_GeneralGetComponentOfType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_GetComponentOfType
(
          SE_4p0_DRM_Class drm_class_a,
          SE_4p0_DRM_Class drm_class_b,
    const SE_Requirement **req_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetDRMTypeStructure
 *
 *   See SE_GeneralGetDRMTypeStructure() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_GetDRMTypeStructure
(
          SE_4p0_DRM_Type                      drm_type,
    const SE_DRM_Type_Structure **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetTypeClassification
 *
 *   See SE_GeneralGetTypeClassification() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_GetTypeClassification
(
    SE_4p0_DRM_Type drm_type,
    SE_Type_Classification *result_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_IsAbstractClass
 *
 *   See SE_GeneralIsAbstractClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p0_IsAbstractClass
(
    SE_4p0_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_IsLegalAggregate
 *
 *   See SE_GeneralIsLegalAggregate() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p0_IsLegalAggregate
(
    SE_4p0_DRM_Class drm_class_a,
    SE_4p0_DRM_Class drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_IsLegalAssociate
 *
 *   See SE_GeneralIsLegalAssociate() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p0_IsLegalAssociate
(
    SE_4p0_DRM_Class drm_class_a,
    SE_4p0_DRM_Class drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_IsLegalComponent
 *
 *   See SE_GeneralIsLegalComponent() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p0_IsLegalComponent
(
    SE_4p0_DRM_Class drm_class_a,
    SE_4p0_DRM_Class drm_class_b
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_IsLinkClass
 *
 *   See SE_GeneralIsLinkClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_Boolean
SE_4p0_IsLinkClass
(
    SE_4p0_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_ithEnumerantInType
 *
 *   See SE_GeneralithEnumerantInType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_ithEnumerantInType
(
          SE_4p0_DRM_Type drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_Enumerant_Structure     **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_ithFieldInClass
 *
 *   See SE_GeneralithFieldInClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_ithFieldInClass
(
          SE_4p0_DRM_Class drm_class,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure     **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_ithFieldInType
 *
 *   See SE_GeneralithFieldInType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_ithFieldInType
(
          SE_4p0_DRM_Type drm_type,
          SE_Short_Integer_Unsigned   i,
    const SE_DRM_Field_Structure     **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_LegalAggregatesCount
 *
 *   See SE_GeneralLegalAggregatesCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_LegalAggregatesCount
(
    SE_4p0_DRM_Class drm_class,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_LegalAggregatesList
 *
 *   See SE_GeneralLegalAggregatesList() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_LegalAggregatesList
(
          SE_4p0_DRM_Class drm_class,
    const SE_Requirement **list_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_LegalAssociationsCount
 *
 *   See SE_GeneralLegalAssociationsCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_LegalAssociationsCount
(
    SE_4p0_DRM_Class drm_class,
    SE_Short_Integer_Unsigned *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_LegalAssociationsList
 *
 *   See SE_GeneralLegalAssociationsList() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_LegalAssociationsList
(
          SE_4p0_DRM_Class drm_class,
    const SE_Requirement **list_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_LegalComponentsCount
 *
 *   See SE_GeneralLegalComponentsCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_LegalComponentsCount
(
    SE_4p0_DRM_Class drm_class,
    SE_Short_Integer_Unsigned     *count_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_LegalComponentsList
 *
 *   See SE_GeneralLegalComponentsList() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_LegalComponentsList
(
          SE_4p0_DRM_Class drm_class,
    const SE_Requirement **list_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_PredefinedFunctionDefinition
 *
 *   See SE_GeneralPredefinedFunctionDefinition() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_PredefinedFunctionDefinition
(
          SE_4p0_Predefined_Function   func,
    const SE_4p0_Predef_Func_Structure **type_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_SuperClass
 *
 *   See SE_GeneralSuperClass() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_4p0_DRM_Class
SE_4p0_SuperClass
(
    SE_4p0_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_GetDRMClassString
 *
 *   See SE_GeneralGetDRMClassString() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern const char *
SE_4p0_GetDRMClassString
(
    SE_4p0_DRM_Class drm_class
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_TypeBasicType
 *
 *   See SE_GeneralTypeBasicType() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_TypeBasicType
(
          SE_4p0_DRM_Type drm_type,
    const SE_DRM_Field_Structure **result_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_TypeCount
 *
 *   See SE_GeneralTypeCount() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern SE_DRM_Status_Code
SE_4p0_TypeCount
(
    SE_Short_Integer_Positive *count_out_ptr
);


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_4p0_TypeName
 *
 *   See SE_GeneralTypeName() for a description.
 *
 *----------------------------------------------------------------------------
 */
extern const char *
SE_4p0_TypeName
(
    SE_4p0_DRM_Type drm_type
);
#ifdef __cplusplus
}
#endif

#endif
