
#ifndef __LocalSpaceRectangular2D_H__
#define __LocalSpaceRectangular2D_H__

#include "BaseSRF.hpp"
#include "Coord.hpp"
#include "Exception.hpp"

namespace srm
{
/** SRF_LocalSpaceRectangular2D class declaration.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author David Shen
    @see BaseSRF_2D
 */
class SRF_LocalSpaceRectangular2D: public BaseSRF_2D
{
public:
   /** Constructor by SRF parameter structure
       @exception This method throws srm::Exception
    */
    static SRF_LocalSpaceRectangular2D* create(      SRM_ORM_Code orm,
                                                     SRM_RT_Code  rt,
                                               const SRM_LSR_2D_Parameters &params);

   /** Constructor by individual SRF parameters
       @exception This method throws srm::Exception
    */
    static SRF_LocalSpaceRectangular2D* create(
                                               SRM_ORM_Code orm,
                                               SRM_RT_Code  rt,
                                               SRM_Axis_Direction forward_direction
                                               );

   /** SRF_LocalSpaceRectangular2D constructor by SRF parameter structure
       @exception This method throws srm::Exception
    */
    static SRF_LocalSpaceRectangular2D* create( SRM_SRF_Parameters_Info srf_params )
    {
          return create( srf_params.value.srf_template.orm_code,
                         srf_params.rt_code,
                         srf_params.value.srf_template.parameters.lsr_2d_srf_parameters );
    }

   /** Returns a 2D coordinate object
    */
    Coord2D* createCoordinate2D(SRM_Long_Float coord_comp1,
                                SRM_Long_Float coord_comp2 );

   /** Returns a reference to the SRF parameter structure
       @exception This method throws srm::Exception
    */
    const SRM_LSR_2D_Parameters &getSRFParameters() const;

   /** Returns the forward_direction SRF parameter value
       @exception This method throws srm::Exception
    */
    SRM_Axis_Direction get_forward_direction() const;

   /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

   /** Returns the class type of this SRF instance
    */
    virtual SRF_ClassType getClassType() const
    {
        return BaseSRF::SRF_TYP_LSR_2D;
    }

   /** Returns true if the SRF parameters are equal
       @note This method is deprecated.  Use the equality operator instead.
    */
    bool isEqual( const SRF_LocalSpaceRectangular2D &srf ) const;

   /** The equality operator
       @note This operator returns true if the SRFs have identical parameter values.
    */
    bool operator==( const SRF_LocalSpaceRectangular2D &rhs ) const;

   /** Returns a copy of this SRF object
       @exception This method throws srm::Exception
    */
    SRF_LocalSpaceRectangular2D* makeCopy() const;

   /** Returns char* of parameter names and their values
       @exception This method throws srm::Exception
    */
    const char* toString();

protected:
    SRF_LocalSpaceRectangular2D( void *impl ) : BaseSRF_2D(impl) {} ///< No stack allocation
    SRF_LocalSpaceRectangular2D &operator =( const SRF_LocalSpaceRectangular2D & ) { return *this; } ///< No copy constructor
    virtual ~SRF_LocalSpaceRectangular2D() {} ///< Use release()
};


inline bool SRF_LocalSpaceRectangular2D::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_LSR_2D)
        return true;
    else
        return BaseSRF_2D::isA(type);
};


/// Shorthand version for SRF_LocalSpaceRectangular2D
typedef SRF_LocalSpaceRectangular2D SRF_LSR_2D;


/** A Coord2D for SRF_LocalSpaceRectangular2D.
    @author David Shen
    @see SRF_LocalSpaceRectangular2D
 */
class Coord2D_LocalSpaceRectangular2D: public Coord2D
{
public:
   /** Constructor
    */
    Coord2D_LocalSpaceRectangular2D(SRF_LocalSpaceRectangular2D *srf,
                                    SRM_Long_Float u = 0.0,
                                    SRM_Long_Float v = 0.0 )
    : Coord2D(srf)
    {
        setComponentValues(u, v);
    }

   /** Copy constructor
    */
    Coord2D_LocalSpaceRectangular2D( const Coord2D_LocalSpaceRectangular2D &coord )
    : Coord2D(coord._srf)
    {
        setComponentValues( coord._values[0], coord._values[1] );
    }

   /** Copies component values to the coordinate
       @note The coordinates must be associated with the same SRF instance.
       @note This method is deprecated.  Use the assignment operator.
       @exception This method throws srm::Exception
    */
    void copyTo( Coord2D_LocalSpaceRectangular2D &coord ) const
    {
        if (coord._srf != _srf)
            throw Exception( SRM_STATCOD_INVALID_SOURCE_COORDINATE, "copyTo: Coordinate associated with a difference SRF" );

        coord._values[0] = _values[0];
        coord._values[1] = _values[1];
    }

   /** Returns true if the coordinate component values are identical
       @note This method is deprecated.  Use the equality operator.
    */
    bool isEqual( const Coord2D_LocalSpaceRectangular2D &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] );
    }

   /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float u, SRM_Long_Float v )
    {
        _values[0] = u;
        _values[1] = v;
    }

   /** Returns the u value
    */
    SRM_Long_Float get_u() const
    {
        return _values[0];
    }

   /** Returns the v value
    */
    SRM_Long_Float get_v() const
    {
        return _values[1];
    }

   /** Sets the u value
    */
    void set_u( SRM_Long_Float value )
    {
        _values[0] = value;
    }

   /** Sets the v value
    */
    void set_v( SRM_Long_Float value )
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
        return Coord::COORD_TYP_LSR_2D;
    }

   /** The equality operator
    */
    bool operator==( const Coord2D_LocalSpaceRectangular2D &rhs ) const;

   /** Returns true if the coordinates are associated with SRFs with identical parameters.
       @note This method should be used to evaluate coordinate compatibility
             before calling the coordinate assignment operator to avoid raising
             runtime exception when operating on incompatible coordinates.
    */
    bool isCompatibleWith( const Coord2D_LocalSpaceRectangular2D &rhs ) const
    {
        return ((*(SRF_LocalSpaceRectangular2D*)(this->_srf)) == (*(SRF_LocalSpaceRectangular2D*)(rhs._srf)));
    }

   /** The assignment operator
       @note This operator will check whether the coordinates are compatible.
       @exception This method throws srm::Exception
    */
    Coord2D_LocalSpaceRectangular2D &operator= ( const Coord2D_LocalSpaceRectangular2D &rhs )
    {
        if((*(SRF_LocalSpaceRectangular2D*)(this->_srf)) == (*(SRF_LocalSpaceRectangular2D*)(rhs._srf)))
        {
            _values[0] = rhs._values[0];
            _values[1] = rhs._values[1];
        }
        else
            throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                            "Coord2D_LocalSpaceRectangular2D op=: incompatible rhs coordinate");

        return *this;
    }
};


inline bool Coord2D_LocalSpaceRectangular2D::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_LSR_2D)
        return true;
    else
        return Coord2D::isA(type);
};


/// Shorthand version for Coord2D_LocalSpaceRectangular2D
typedef Coord2D_LocalSpaceRectangular2D Coord2D_LSR_2D;

} // namespace srm

#endif // _LocalSpaceRectangular2D_h
