
#ifndef __HeliosphericEarthEquatorial_H__
#define __HeliosphericEarthEquatorial_H__

#include "BaseSRF.hpp"
#include "Coord.hpp"
#include "Exception.hpp"

namespace srm
{
/** SRF_HeliosphericEarthEquatorial class declaration.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author David Shen
    @see BaseSRF_3D
 */
class SRF_HeliosphericEarthEquatorial: public BaseSRF_3D
{
public:
   /** SRF_HeliosphericEarthEquatorial only constructor by ORM code
       @exception This method throws srm::Exception
    */
    static SRF_HeliosphericEarthEquatorial* create( SRM_ORM_Code orm,
                                                    SRM_RT_Code  rt );

   /** SRF_HeliosphericEarthEquatorial constructor by ORM parameters
       @exception This method throws srm::Exception
    */
    static SRF_HeliosphericEarthEquatorial* create( SRM_SRF_Parameters_Info srf_params )
    {
        return create( srf_params.value.srf_template.orm_code, srf_params.rt_code );
    }

   /** Returns a 3D coordinate object
    */
    Coord3D* createCoordinate3D(SRM_Long_Float coord_comp1,
                                SRM_Long_Float coord_comp2,
                                SRM_Long_Float coord_comp3 );

   /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;


   /** Returns the class type of this SRF instance
    */
    virtual SRF_ClassType getClassType() const
    {
        return BaseSRF::SRF_TYP_HEEQ;
    }

   /** Returns true if the SRF parameters are equal
       @note This method is deprecated.  Use the equality operator instead.
    */
    bool isEqual( const SRF_HeliosphericEarthEquatorial &srf ) const;

   /** The equality operator
       @note This operator returns true if the SRFs have identical parameter values.
    */
    bool operator==( const SRF_HeliosphericEarthEquatorial &rhs ) const;

   /** Returns a copy of this SRF object
       @exception This method throws srm::Exception
    */
    SRF_HeliosphericEarthEquatorial* makeCopy() const;

   /** Returns char* of parameter names and their values
       @exception This method throws srm::Exception
    */
    const char* toString();

protected:
    SRF_HeliosphericEarthEquatorial( void *impl ) : BaseSRF_3D(impl) {} ///< No stack allocation
    SRF_HeliosphericEarthEquatorial &operator =( const SRF_HeliosphericEarthEquatorial & ) { return *this; } ///< No copy constructor
    virtual ~SRF_HeliosphericEarthEquatorial() {} ///< Use release()
};


inline bool SRF_HeliosphericEarthEquatorial::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_HEEQ)
        return true;
    else
        return BaseSRF_3D::isA(type);
};


/// Shorthand version for SRF_HeliosphericEarthEquatorial
typedef SRF_HeliosphericEarthEquatorial SRF_HEEQ;


/** A Coord3D for SRF_HeliosphericEarthEquatorial.
    @author David Shen
    @see SRF_HeliosphericEarthEquatorial
 */
class Coord3D_HeliosphericEarthEquatorial: public Coord3D
{
public:
   /** Constructor
    */
    Coord3D_HeliosphericEarthEquatorial( SRF_HeliosphericEarthEquatorial *srf,
                                         SRM_Long_Float longitude = 0.0,
                                         SRM_Long_Float latitude = 0.0,
                                         SRM_Long_Float radius = 0.0 )
    : Coord3D(srf)
    {
        setComponentValues(longitude, latitude, radius);
    }

   /** Copy constructor
    */
    Coord3D_HeliosphericEarthEquatorial( const Coord3D_HeliosphericEarthEquatorial &coord )
    : Coord3D(coord._srf)
    {
        setComponentValues( coord._values[0], coord._values[1], coord._values[2] );
    }

   /** Copies component values to the coordinate
       @note The coordinates must be associated with the same SRF instance.
       @note This method is deprecated.  Use the assignment operator.
       @exception This method throws srm::Exception
    */
    void copyTo( Coord3D_HeliosphericEarthEquatorial &coord ) const
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
    bool isEqual( const Coord3D_HeliosphericEarthEquatorial &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] &&
                _values[2] == coord._values[2] );
    }

   /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float longitude, SRM_Long_Float latitude, SRM_Long_Float radius )
    {
        _values[0] = longitude;
        _values[1] = latitude;
        _values[2] = radius;
    }

    /** Returns the longitude value
     */
    SRM_Long_Float get_longitude() const
    {
        return _values[0];
    }

   /** Returns the latitude value
     */
    SRM_Long_Float get_latitude() const
    {
        return _values[1];
    }

   /** Returns the radius value
     */
    SRM_Long_Float get_radius() const
    {
        return _values[2];
    }

   /** Sets the longitude value
     */
    void set_longitude( SRM_Long_Float value )
    {
        _values[0] = value;
    }

   /** Sets the latitude value
     */
    void set_latitude( SRM_Long_Float value )
    {
        _values[1] = value;
    }

   /** Sets the radius value
     */
    void set_radius( SRM_Long_Float value )
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
        return Coord::COORD_TYP_HEEQ;
    }

   /** The equality operator
     */
    bool operator==( const Coord3D_HeliosphericEarthEquatorial &rhs ) const;

   /** Returns true if the coordinates are associated with SRFs with identical parameters.
       @note This method should be used to evaluate coordinate compatibility before
             calling the coordinate assignment operator to avoid raising runtime exception
             when operating on incompatible coordinates.
    */
    bool isCompatibleWith( const Coord3D_HeliosphericEarthEquatorial &rhs ) const
    {
        return ((*(SRF_HeliosphericEarthEquatorial*)(this->_srf)) == (*(SRF_HeliosphericEarthEquatorial*)(rhs._srf)));
    }

   /** The assignment operator
       @note This operator will check whether the coordinates are compatible.
       @exception This method throws srm::Exception
    */
    Coord3D_HeliosphericEarthEquatorial &operator= ( const Coord3D_HeliosphericEarthEquatorial &rhs )
    {
        if((*(SRF_HeliosphericEarthEquatorial*)(this->_srf)) == (*(SRF_HeliosphericEarthEquatorial*)(rhs._srf)))
        {
            _values[0] = rhs._values[0];
            _values[1] = rhs._values[1];
            _values[2] = rhs._values[2];
        }
        else
            throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                            "Coord3D_HeliosphericEarthEquatorial op=: incompatible rhs coordinate");

        return *this;
    }
};


inline bool Coord3D_HeliosphericEarthEquatorial::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_HEEQ)
        return true;
    else
        return Coord3D::isA(type);
};


/// Shorthand version for Coord3D_HeliosphericEarthEquatorial
typedef Coord3D_HeliosphericEarthEquatorial Coord3D_HEEQ;

} // namespace srm

#endif // _HeliosphericEarthEquatorial_h
