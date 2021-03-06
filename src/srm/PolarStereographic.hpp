
#ifndef __PolarStereographic_H__
#define __PolarStereographic_H__

#include "BaseSRF.hpp"
#include "Coord.hpp"
#include "Exception.hpp"

namespace srm
{
/** SRF_PolarStereographic class declaration.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author David Shen
    @see BaseSRF_MapProjection
*/
class SRF_PolarStereographic: public BaseSRF_MapProjection
{
public:
   /** Constructor by SRF parameter structure
       @exception This method throws srm::Exception
    */
    static SRF_PolarStereographic* create(      SRM_ORM_Code orm,
                                                SRM_RT_Code  rt,
                                          const SRM_PS_Parameters &params);

   /** Constructor by individual SRF parameters
       @exception This method throws srm::Exception
    */
    static SRF_PolarStereographic* create(
                                          SRM_ORM_Code     orm,
                                          SRM_RT_Code      rt,
                                          SRM_Polar_Aspect polar_aspect,
                                          SRM_Long_Float   origin_longitude,
                                          SRM_Long_Float   central_scale,
                                          SRM_Long_Float   false_easting,
                                          SRM_Long_Float   false_northing
                                          );

   /** SRF_PolarStereographic constructor by SRF parameter structure
       @exception This method throws srm::Exception
    */
    static SRF_PolarStereographic* create( SRM_SRF_Parameters_Info srf_params )
    {
        return create(srf_params.value.srf_template.orm_code,
                      srf_params.rt_code,
                      srf_params.value.srf_template.parameters.ps_srf_parameters);
    }

   /** Returns a 3D coordinate object
    */
    Coord3D* createCoordinate3D(SRM_Long_Float coord_comp1,
                                SRM_Long_Float coord_comp2,
                                SRM_Long_Float coord_comp3 );

   /** Returns a surface coordinate object
    */
    CoordSurf* createSurfaceCoordinate(SRM_Long_Float coord_surf_comp1,
                                       SRM_Long_Float coord_surf_comp2 );

   /** Returns a reference to the SRF parameter structure
       @exception This method throws srm::Exception
    */
    const SRM_PS_Parameters &getSRFParameters() const;

   /** Returns the polar_aspect SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Polar_Aspect get_polar_aspect() const;

   /** Returns the origin_longitude SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_origin_longitude() const;

   /** Returns the central_scale SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_central_scale() const;

   /** Returns the false_easting SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_false_easting() const;

   /** Returns the false_northing SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_false_northing() const;

   /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

   /** Returns the class type of this SRF instance
    */
    virtual SRF_ClassType getClassType() const
    {
        return BaseSRF::SRF_TYP_PS;
    }

   /** Returns true if the SRF parameters are equal
       @note This method is deprecated.  Use the equality operator instead.
    */
    bool isEqual( const SRF_PolarStereographic &srf ) const;

   /** The equality operator
       @note This operator returns true if the SRFs have identical parameter values.
    */
    bool operator==( const SRF_PolarStereographic &rhs ) const;

   /** Returns a copy of this SRF object
       @exception This method throws srm::Exception
    */
    SRF_PolarStereographic* makeCopy() const;

   /** Changes a coordinate's values to this SRF (optimized implementation).
       @note The destination coordinate must have been created using this SRF.
       @param src_coord in: the source coordinate in some other SRF
       @param des_coord in/out: the destination coordinate in this SRF
       @return validity code for the destination coordinate
       @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeCoordinate3DSRF(const Coord3D &src_coord,
                                                                    Coord3D &des_coord);

   /** Returns char* of parameter names and their values
       @exception This method throws srm::Exception
    */
    const char* toString();

protected:
    friend class BaseSRF;
    friend class BaseSRF_3D;
    friend class BaseSRF_WithEllipsoidalHeight;
    SRF_PolarStereographic( void *impl ); ///< No stack allocation
    SRF_PolarStereographic &operator =( const SRF_PolarStereographic & ) { return *this; } ///< No copy constructor
    virtual ~SRF_PolarStereographic(); ///< Use release()
};


inline bool SRF_PolarStereographic::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_PS)
        return true;
    else
        return BaseSRF_MapProjection::isA(type);
};


/// Shorthand version for SRF_PolarStereographic
typedef SRF_PolarStereographic SRF_PS;


/** A Coord3D for SRF_PolarStereographic.
    @author David Shen
    @see SRF_PolarStereographic
 */
class Coord3D_PolarStereographic: public Coord3D
{
public:
   /** Constructor
    */
    Coord3D_PolarStereographic(SRF_PolarStereographic *srf,
                               SRM_Long_Float easting = 0.0,
                               SRM_Long_Float northing = 0.0,
                               SRM_Long_Float ellipsoidal_height = 0.0)
    : Coord3D(srf)
    {
        setComponentValues(easting, northing, ellipsoidal_height);
    }

   /** Copy constructor
    */
    Coord3D_PolarStereographic( const Coord3D_PolarStereographic &coord )
    : Coord3D(coord._srf)
    {
        setComponentValues(coord._values[0], coord._values[1], coord._values[2]);
    }

   /** Copies component values to the coordinate
       @note The coordinates must be associated with the same SRF instance.
       @note This method is deprecated.  Use the assignment operator.
       @exception This method throws srm::Exception
    */
    void copyTo( Coord3D_PolarStereographic &coord ) const
    {
        if (coord._srf != _srf)
            throw Exception( SRM_STATCOD_INVALID_SOURCE_COORDINATE, "copyTo: Coordinate associated with a difference SRF" );

        coord._values[0] = _values[0];
        coord._values[1] = _values[1];
        coord._values[2] = _values[2];
    }

   /** Returns true if the coordinate component values are identical
       @note This method is deprecated.  Use the equality operator.
    */
    bool isEqual( const Coord3D_PolarStereographic &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] &&
                _values[2] == coord._values[2]);
    }

   /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float easting, SRM_Long_Float northing, SRM_Long_Float ellipsoidal_height )
    {
        _values[0] = easting;
        _values[1] = northing;
        _values[2] = ellipsoidal_height;
    }

   /** Returns the easting value
    */
    SRM_Long_Float get_easting() const
    {
        return _values[0];
    }

   /** Returns the northing value
    */
    SRM_Long_Float get_northing() const
    {
        return _values[1];
    }

   /** Returns the ellipsoidal_height value
    */
    SRM_Long_Float get_ellipsoidal_height() const
    {
        return _values[2];
    }

   /** Sets the easting value
    */
    void set_easting( SRM_Long_Float value )
    {
        _values[0] = value;
    }

   /** Sets the northing value
    */
    void set_northing( SRM_Long_Float value )
    {
        _values[1] = value;
    }

   /** Sets the ellipsoidal_height value
    */
    void set_ellipsoidal_height( SRM_Long_Float value )
    {
        _values[2] = value;
    }

   /** Returns true if this coordinate is of the given class type
    */
    virtual bool isA( Coord_ClassType type ) const;

   /** Returns true if this SRF is of the given class type
    */
    virtual Coord_ClassType getClassType() const
    {
        return Coord::COORD_TYP_PS;
    }

   /** The equality operator
    */
    bool operator==( const Coord3D_PolarStereographic &rhs ) const;

    /** Returns true if the coordinates are associated with SRFs with identical parameters.
        @note This method should be used to evaluate coordinate compatibility
              before calling the coordinate assignment operator to avoid raising
              runtime exception when operating on incompatible coordinates.
     */
    bool isCompatibleWith( const Coord3D_PolarStereographic &rhs ) const
    {
        return ((*(SRF_PolarStereographic*)(this->_srf)) == (*(SRF_PolarStereographic*)(rhs._srf)));
    }

   /** The assignment operator
       @note This operator will check whether the coordinates are compatible.
       @exception This method throws srm::Exception
    */
    Coord3D_PolarStereographic &operator= ( const Coord3D_PolarStereographic &rhs )
    {
        if((*(SRF_PolarStereographic*)(this->_srf)) == (*(SRF_PolarStereographic*)(rhs._srf)))
        {
            _values[0] = rhs._values[0];
            _values[1] = rhs._values[1];
            _values[2] = rhs._values[2];
        }
        else
            throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                            "Coord3D_PolarStereographic op=: incompatible rhs coordinate");

        return *this;
    }
};


inline bool Coord3D_PolarStereographic::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_PS)
        return true;
    else
        return Coord3D::isA(type);
};


/// Shorthand version for Coord3D_PolarStereographic
typedef Coord3D_PolarStereographic Coord3D_PS;


/** A CoordSurf for SRF_PolarStereographic.
    @author David Shen
    @see SRF_PolarStereographic
 */
class CoordSurf_PolarStereographic: public CoordSurf
{
public:
   /** Constructor
    */
    CoordSurf_PolarStereographic(SRF_PolarStereographic *srf,
                                 SRM_Long_Float easting = 0.0,
                                 SRM_Long_Float northing = 0.0 )
    : CoordSurf(srf)
    {
        setComponentValues(easting, northing);
    }

   /** Copy constructor
    */
    CoordSurf_PolarStereographic( const CoordSurf_PolarStereographic &coord )
    : CoordSurf(coord._srf)
    {
        setComponentValues( coord._values[0], coord._values[1] );
    }

   /** Copies component values to the coordinate
       @note The coordinates must be associated with the same SRF instance.
       @note This method is deprecated.  Use the assignment operator.
       @exception This method throws srm::Exception
    */
    void copyTo( CoordSurf_PolarStereographic &coord ) const
    {
        if (coord._srf != _srf)
            throw Exception( SRM_STATCOD_INVALID_SOURCE_COORDINATE, "copyTo: Coordinate associated with a difference SRF" );

        coord._values[0] = _values[0];
        coord._values[1] = _values[1];
    }

   /** Returns true if the coordinate component values are identical
        @note This method is deprecated.  Use the equality operator.
    */
    bool isEqual( const CoordSurf_PolarStereographic &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] );
    }

    /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float easting, SRM_Long_Float northing )
    {
        _values[0] = easting;
        _values[1] = northing;
    }

    /** Returns the easting value
    */
    SRM_Long_Float get_easting() const
    {
        return _values[0];
    }

    /** Returns the northing value
    */
    SRM_Long_Float get_northing() const
    {
        return _values[1];
    }

    /** Sets the easting value
    */
    void set_easting( SRM_Long_Float value )
    {
        _values[0] = value;
    }

    /** Sets the northing value
    */
    void set_northing( SRM_Long_Float value )
    {
        _values[1] = value;
    }

   /** Returns true if this coordinate is of the given class type
    */
    virtual bool isA( Coord_ClassType type ) const;

    /** Returns true if this SRF is of the given class type
    */
    virtual Coord_ClassType getClassType() const
    {
        return Coord::COORD_TYP_SURF_PS;
    }

   /** The equality operator
    */
    bool operator==( const CoordSurf_PolarStereographic &rhs ) const;

   /** Returns true if the coordinates are associated with SRFs with identical parameters.
       @note This method should be used to evaluate coordinate compatibility
             before calling the coordinate assignment operator to avoid raising
             runtime exception when operating on incompatible coordinates.
    */
    bool isCompatibleWith( const CoordSurf_PolarStereographic &rhs ) const
    {
        return ((*(SRF_PolarStereographic*)(this->_srf)) == (*(SRF_PolarStereographic*)(rhs._srf)));
    }

   /** The assignment operator
       @note This operator will check whether the coordinates are compatible.
       @exception This method throws srm::Exception
    */
    CoordSurf_PolarStereographic &operator= ( const CoordSurf_PolarStereographic &rhs )
    {
        if((*(SRF_PolarStereographic*)(this->_srf)) == (*(SRF_PolarStereographic*)(rhs._srf)))
        {
            _values[0] = rhs._values[0];
            _values[1] = rhs._values[1];
        }
        else
            throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                            "CoordSurf_PolarStereographic op=: incompatible rhs coordinate");

        return *this;
    }
};


inline bool CoordSurf_PolarStereographic::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_SURF_PS)
        return true;
    else
        return CoordSurf::isA(type);
};


/// Shorthand version for CoordSurf_PolarStereographic
typedef CoordSurf_PolarStereographic CoordSurf_PS;


} // namespace srm

#endif // _PolarStereographic_h
