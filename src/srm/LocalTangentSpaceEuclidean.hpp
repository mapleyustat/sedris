
#ifndef __LocalTangentSpaceEuclidean_H__
#define __LocalTangentSpaceEuclidean_H__

#include "BaseSRF.hpp"
#include "Coord.hpp"
#include "Exception.hpp"

namespace srm
{
/** SRF_LocalTangentSpaceEuclidean class declaration.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author David Shen
    @see BaseSRF_WithTangentPlaneSurface
 */
class SRF_LocalTangentSpaceEuclidean: public BaseSRF_WithTangentPlaneSurface
{
public:
   /** Constructor by SRF parameter structure
       @exception This method throws srm::Exception
    */
    static SRF_LocalTangentSpaceEuclidean* create
    (
              SRM_ORM_Code         orm,
              SRM_RT_Code          rt,
        const SRM_LTSE_Parameters &params
    );

   /** Constructor by individual SRF parameters
       @exception This method throws srm::Exception
    */
    static SRF_LocalTangentSpaceEuclidean* create(
                                                  SRM_ORM_Code   orm,
                                                  SRM_RT_Code    rt,
                                                  SRM_Long_Float geodetic_longitude,
                                                  SRM_Long_Float geodetic_latitude,
                                                  SRM_Long_Float azimuth,
                                                  SRM_Long_Float x_false_origin,
                                                  SRM_Long_Float y_false_origin,
                                                  SRM_Long_Float height_offset
                                                  );

   /** SRF_LocalTangentSpaceEuclidean constructor by SRF parameter structure
       @exception This method throws srm::Exception
    */
    static SRF_LocalTangentSpaceEuclidean* create( SRM_SRF_Parameters_Info srf_params )
    {
        return create(srf_params.value.srf_template.orm_code,
                      srf_params.rt_code,
                      srf_params.value.srf_template.parameters.ltse_srf_parameters );
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
    const SRM_LTSE_Parameters &getSRFParameters() const;

   /** Returns the geodetic_longitude SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_geodetic_longitude() const;

   /** Returns the geodetic_latitude SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_geodetic_latitude() const;

   /** Returns the azimuth SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_azimuth() const;

   /** Returns the x_false_origin SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_x_false_origin() const;

   /** Returns the y_false_origin SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_y_false_origin() const;

   /** Returns the height_offset SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Long_Float get_height_offset() const;

   /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

   /** Returns the class type of this SRF instance
    */
    virtual SRF_ClassType getClassType() const
    {
        return BaseSRF::SRF_TYP_LTSE;
    }

   /** Returns true if the SRF parameters are equal
       @note This method is deprecated.  Use the equality operator instead.
    */
    bool isEqual( const SRF_LocalTangentSpaceEuclidean &srf ) const;

   /** The equality operator
       @note This operator returns true if the SRFs have identical parameter values.
    */
    bool operator==( const SRF_LocalTangentSpaceEuclidean &rhs ) const;

   /** Returns a copy of this SRF object
       @exception This method throws srm::Exception
    */
    SRF_LocalTangentSpaceEuclidean* makeCopy() const;

   /** Changes a coordinate's values to this SRF (optimized implementation).
       @note The destination coordinate must have been created using this SRF.
       @param src_coord in: the source coordinate in some other SRF
       @param des_coord in/out: the destination coordinate in this SRF
       @return validity code for the destination coordinate
       @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeCoordinate3DSRF(const Coord3D &src_coord,
                                                                    Coord3D &des_coord );

   /** Returns char* of parameter names and their values
       @exception This method throws srm::Exception
    */
    const char* toString();

protected:
    friend class BaseSRF;
    friend class BaseSRF_3D;
    friend class BaseSRF_WithEllipsoidalHeight;
    SRF_LocalTangentSpaceEuclidean( void *impl ); ///< No stack allocation
    SRF_LocalTangentSpaceEuclidean &operator =( const SRF_LocalTangentSpaceEuclidean & ) { return *this; } ///< No copy constructor
    virtual ~SRF_LocalTangentSpaceEuclidean(); ///< Use release()
};


inline bool SRF_LocalTangentSpaceEuclidean::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_LTSE)
        return true;
    else
        return BaseSRF_WithTangentPlaneSurface::isA(type);
};


/// Shorthand version for SRF_LocalTangentSpaceEuclidean
typedef SRF_LocalTangentSpaceEuclidean SRF_LTSE;


/** A Coord3D for SRF_LocalTangentSpaceEuclidean.
    @author David Shen
    @see SRF_LocalTangentSpaceEuclidean
 */
class Coord3D_LocalTangentSpaceEuclidean: public Coord3D
{
public:
   /** Constructor
    */
    Coord3D_LocalTangentSpaceEuclidean(SRF_LocalTangentSpaceEuclidean *srf,
                                       SRM_Long_Float x = 0.0,
                                       SRM_Long_Float y = 0.0,
                                       SRM_Long_Float height = 0.0 )
    : Coord3D(srf)
    {
        setComponentValues(x, y, height);
    }

   /** Copy constructor
    */
    Coord3D_LocalTangentSpaceEuclidean( const Coord3D_LocalTangentSpaceEuclidean &coord )
    : Coord3D(coord._srf)
    {
        setComponentValues( coord._values[0], coord._values[1], coord._values[2] );
    }

   /** Copies component values to the coordinate
       @note The coordinates must be associated with the same SRF instance.
       @note This method is deprecated.  Use the assignment operator.
       @exception This method throws srm::Exception
    */
    void copyTo( Coord3D_LocalTangentSpaceEuclidean &coord ) const
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
    bool isEqual( const Coord3D_LocalTangentSpaceEuclidean &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] &&
                _values[2] == coord._values[2] );
    }

   /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float x, SRM_Long_Float y, SRM_Long_Float height )
    {
        _values[0] = x;
        _values[1] = y;
        _values[2] = height;
    }

   /** Returns the x value
    */
    SRM_Long_Float get_x() const
    {
        return _values[0];
    }

   /** Returns the y value
    */
    SRM_Long_Float get_y() const
    {
        return _values[1];
    }

   /** Returns the height value
    */
    SRM_Long_Float get_height() const
    {
        return _values[2];
    }

   /** Sets the x value
    */
    void set_x( SRM_Long_Float value )
    {
        _values[0] = value;
    }

   /** Sets the y value
    */
    void set_y( SRM_Long_Float value )
    {
        _values[1] = value;
    }

   /** Sets the height value
    */
    void set_height( SRM_Long_Float value )
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
        return Coord::COORD_TYP_LTSE;
    }

   /** The equality operator
    */
    bool operator==( const Coord3D_LocalTangentSpaceEuclidean &rhs ) const;

   /** Returns true if the coordinates are associated with SRFs with identical parameters.
       @note This method should be used to evaluate coordinate compatibility before
             calling the coordinate assignment operator to avoid raising runtime exception
             when operating on incompatible coordinates.
    */
    bool isCompatibleWith( const Coord3D_LocalTangentSpaceEuclidean &rhs ) const
    {
        return ((*(SRF_LocalTangentSpaceEuclidean*)(this->_srf)) == (*(SRF_LocalTangentSpaceEuclidean*)(rhs._srf)));
    }

   /** The assignment operator
       @note This operator will check whether the coordinates are compatible.
       @exception This method throws srm::Exception
    */
    Coord3D_LocalTangentSpaceEuclidean &operator= ( const Coord3D_LocalTangentSpaceEuclidean &rhs )
    {
        if((*(SRF_LocalTangentSpaceEuclidean*)(this->_srf)) == (*(SRF_LocalTangentSpaceEuclidean*)(rhs._srf)))
        {
            _values[0] = rhs._values[0];
            _values[1] = rhs._values[1];
            _values[2] = rhs._values[2];
        }
        else
            throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                            "Coord3D_LocalTangentSpaceEuclidean op=: incompatible rhs coordinate");

        return *this;
    }
};


inline bool Coord3D_LocalTangentSpaceEuclidean::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_LTSE)
        return true;
    else
        return Coord3D::isA(type);
};


/// Shorthand version for Coord3D_LocalTangentSpaceEuclidean
typedef Coord3D_LocalTangentSpaceEuclidean Coord3D_LTSE;


/** A CoordSurf for SRF_LocalTangentSpaceEuclidean.
    @author David Shen
    @see SRF_LocalTangentSpaceEuclidean
 */
class CoordSurf_LocalTangentSpaceEuclidean: public CoordSurf
{
public:
   /** Constructor
    */
    CoordSurf_LocalTangentSpaceEuclidean(SRF_LocalTangentSpaceEuclidean *srf,
                                         SRM_Long_Float x = 0.0,
                                         SRM_Long_Float y = 0.0 )
    : CoordSurf(srf)
    {
        setComponentValues(x, y);
    }

   /** Copy constructor
    */
    CoordSurf_LocalTangentSpaceEuclidean( const CoordSurf_LocalTangentSpaceEuclidean &coord )
    : CoordSurf(coord._srf)
    {
        setComponentValues( coord._values[0], coord._values[1] );
    }

  /** Copies component values to the coordinate
      @note The coordinates must be associated with the same SRF instance.
      @note This method is deprecated.  Use the assignment operator.
      @exception This method throws srm::Exception
   */
    void copyTo( CoordSurf_LocalTangentSpaceEuclidean &coord ) const
    {
        if (coord._srf != _srf)
            throw Exception( SRM_STATCOD_INVALID_SOURCE_COORDINATE, "copyTo: Coordinate associated with a difference SRF" );

        coord._values[0] = _values[0];
        coord._values[1] = _values[1];
    }

   /** Returns true if the coordinate component values are identical
       @note This method is deprecated.  Use the equality operator.
    */
    bool isEqual( const CoordSurf_LocalTangentSpaceEuclidean &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] );
    }

   /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float x, SRM_Long_Float y )
    {
        _values[0] = x;
        _values[1] = y;
    }

   /** Returns the x value
    */
    SRM_Long_Float get_x() const
    {
        return _values[0];
    }

   /** Returns the y value
    */
    SRM_Long_Float get_y() const
    {
        return _values[1];
    }

   /** Sets the x value
    */
    void set_x( SRM_Long_Float value )
    {
        _values[0] = value;
    }

   /** Sets the y value
    */
    void set_y( SRM_Long_Float value )
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
        return Coord::COORD_TYP_SURF_LTSE;
    }

   /** The equality operator
    */
    bool operator==( const CoordSurf_LocalTangentSpaceEuclidean &rhs ) const;

   /** Returns true if the coordinates are associated with SRFs with identical parameters.
       @note This method should be used to evaluate coordinate compatibility before
             calling the coordinate assignment operator to avoid raising runtime exception
             when operating on incompatible coordinates.
    */
    bool isCompatibleWith( const CoordSurf_LocalTangentSpaceEuclidean &rhs ) const
    {
        return ((*(SRF_LocalTangentSpaceEuclidean*)(this->_srf)) == (*(SRF_LocalTangentSpaceEuclidean*)(rhs._srf)));
    }

   /** The assignment operator
       @note This operator will check whether the coordinates are compatible.
       @note Compatible coordinates are associated with SRFs with identical parameters.
       @exception This method throws srm::Exception
    */
    CoordSurf_LocalTangentSpaceEuclidean &operator= ( const CoordSurf_LocalTangentSpaceEuclidean &rhs )
    {
        if((*(SRF_LocalTangentSpaceEuclidean*)(this->_srf)) == (*(SRF_LocalTangentSpaceEuclidean*)(rhs._srf)))
        {
            _values[0] = rhs._values[0];
            _values[1] = rhs._values[1];
        }
        else
            throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                            "CoordSurf_LocalTangentSpaceEuclidean op=: incompatible rhs coordinate");

        return *this;
    }
};


inline bool CoordSurf_LocalTangentSpaceEuclidean::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_SURF_LTSE)
        return true;
    else
        return CoordSurf::isA(type);
};


/// Shorthand version for CoordSurf_LocalTangentSpaceEuclidean
typedef CoordSurf_LocalTangentSpaceEuclidean CoordSurf_LTSE;

} // namespace srm

#endif // _LocalTangentSpaceEuclidean_h
