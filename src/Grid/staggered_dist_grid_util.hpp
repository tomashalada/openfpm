/*
 * staggered_util.hpp
 *
 *  Created on: Aug 19, 2015
 *      Author: i-bird
 */

#ifndef SRC_GRID_STAGGERED_DIST_GRID_UTIL_HPP_
#define SRC_GRID_STAGGERED_DIST_GRID_UTIL_HPP_

#include "util/common.hpp"
#include "VTKWriter/VTKWriter.hpp"
#include "util/convert.hpp"


/*! \brief write a property that has attributes
 *
 * \tparam ele object we are writing
 * \tparam vtk vtk writer
 * \tparam true in case the basic object has attributes
 *
 */
template<typename ele, typename vtk, bool has_attributes=has_attributes<ele>::value>
struct vtk_write
{
	/*! \brief Add the grid with attributes name
	 *
	 * \param vtk_w VTK writer
	 * \param output where to write
	 * \param i property to write
	 *
	 */
	vtk_write(vtk vtk_w, const std::string output, const size_t i)
	{
		vtk_w.write(output + "_" + ele::attributes::name[i] + ".vtk",ele::attributes::name[i]);
	}
};

/*! \brief Add to the vtk writer the key
 *
 * \tparam ele object we are writing
 * \tparam vtk vtk writer
 * \tparam false in case the basic object has not attributes
 *
 */
template<typename ele, typename vtk>
struct vtk_write<ele,vtk,false>
{
	/*! \brief Add the grid with attributes name
	 *
	 * \param vtk_w VTK writer
	 * \param output where to write
	 * \param i property to write
	 *
	 */
	vtk_write(vtk vtk_w, const std::string output, const size_t i)
	{
		vtk_w.write(output + "_" + std::to_string(i) + ".vtk","attr" + std::to_string(i));
	}
};


/*! \brief Classes to get the number of components of the properties
 *
 */
template<typename T>
struct extends
{
	static inline size_t mul()
	{
		return 1;
	}

	static inline size_t dim()
	{
		return 0;
	}
};

//! Partial specialization for N=1 1D-Array
template<typename T,size_t N1>
struct extends<T[N1]>
{
	static inline size_t mul()
	{
		return N1;
	}

	static inline size_t dim()
	{
		return 1;
	}
};

//! Partial specialization for N=2 2D-Array
template<typename T,size_t N1,size_t N2>
struct extends<T[N1][N2]>
{
	static inline size_t mul()
	{
		return N1 * N2;
	}

	static inline size_t dim()
	{
		return 2;
	}
};

//! Partial specialization for N=3
template<typename T,size_t N1,size_t N2,size_t N3>
struct extends<T[N1][N2][N3]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3;
	}

	static inline size_t dim()
	{
		return 3;
	}
};

//! Partial specialization for N=4
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4>
struct extends<T[N1][N2][N3][N4]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4;
	}

	static inline size_t dim()
	{
		return 4;
	}
};

//! Partial specialization for N=5
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4,size_t N5>
struct extends<T[N1][N2][N3][N4][N5]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4 * N5;
	}

	static inline size_t dim()
	{
		return 5;
	}
};

//! Partial specialization for N=6
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4,size_t N5, size_t N6>
struct extends<T[N1][N2][N3][N4][N5][N6]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4 * N5 * N6;
	}

	static inline size_t dim()
	{
		return 6;
	}
};

//! Partial specialization for N=7
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4,size_t N5, size_t N6, size_t N7>
struct extends<T[N1][N2][N3][N4][N5][N6][N7]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4 * N5 * N6 * N7;
	}

	static inline size_t dim()
	{
		return 7;
	}
};

//! Partial specialization for N=8
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4,size_t N5, size_t N6, size_t N7, size_t N8>
struct extends<T[N1][N2][N3][N4][N5][N6][N7][N8]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4 * N5 * N6 * N7 * N8;
	}

	static inline size_t dim()
	{
		return 8;
	}
};

//! Partial specialization for N=9
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4,size_t N5, size_t N6, size_t N7, size_t N8, size_t N9>
struct extends<T[N1][N2][N3][N4][N5][N6][N7][N8][N9]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4 * N5 * N6 * N7 * N8 * N9;
	}

	static inline size_t dim()
	{
		return 9;
	}
};

//! Partial specialization for N=10
template<typename T,size_t N1,size_t N2,size_t N3,size_t N4,size_t N5, size_t N6, size_t N7, size_t N8, size_t N9, size_t N10>
struct extends<T[N1][N2][N3][N4][N5][N6][N7][N8][N9][N10]>
{
	static inline size_t mul()
	{
		return N1 * N2 * N3 * N4 * N5 * N6 * N7 * N8 * N9 * N10;
	}

	static inline size_t dim()
	{
		return 10;
	}
};

///////////////////// Copy grid extends

/*! \brief Classes to copy each component into a grid and add to the VTKWriter the grid
 *
 * \param T property to write
 * \param dim dimansionality
 * \param St type of space
 * \param VTKW VTK writer
 * \param
 *
 */
template<typename T>
struct write_stag
{
	/*! \brieg write the staggered grid
	 *
	 * \tparam p_val property we are going to write
	 * \tparam sg staggered grid type
	 * \tparam v_g vector of grids
	 *
	 * \param st_g staggered grid
	 * \param v_g vector of grids
	 * \param i local grid of the staggered grid we are writing
	 *
	 */
	template<unsigned int p_val, typename sg, typename v_g> static inline void write(sg & st_g, v_g & vg,size_t lg)
	{
		// Add a grid;
		vg.add();
		size_t k = vg.size() - 1;

		// Get the source and destination grid
		auto & g_src = st_g.get_loc_grid(lg);
		auto & g_dst = vg.get(k);

		// Set dimensions and memory
		g_dst.resize(g_src.getGrid().getSize());

		// copy

		auto it = vg.get(k).getIterator();

		while(it.isNext())
		{
			g_dst.template get<0>(it.get()) = g_src.template get<p_val>(it.get());

			++it;
		}
	}
};

/*! \brief for each component add a grid fill it, and add to the VTK writer
 *
 * \param T Property to copy
 * \param N1 number of components
 *
 */
template<typename T,size_t N1>
struct write_stag<T[N1]>
{
	/*! \brieg write the staggered grid
	 *
	 * \tparam p_val property we are going to write
	 * \tparam sg staggered grid type
	 * \tparam v_g vector of grids
	 *
	 * \param st_g staggered grid
	 * \param v_g vector of grids
	 * \param i local grid of the staggered grid we are writing
	 *
	 */
	template<unsigned int p_val, typename sg, typename v_g> static inline void write(sg & st_g, v_g & vg,size_t lg)
	{
		for (size_t i = 0 ; i < N1 ; i++)
		{
			// Add a grid;
			vg.add();
			size_t k = vg.size() - 1;

			// Get the source and destination grid
			auto & g_src = st_g.get_loc_grid(lg);
			auto & g_dst = vg.get(k);

			// Set dimensions and memory
			g_dst.resize(g_src.getGrid().getSize());

			auto it = vg.get(k).getIterator();

			while(it.isNext())
			{
				g_dst.template get<0>(it.get()) = g_src.template get<p_val>(it.get())[i];

				++it;
			}
		}
	}
};

//! Partial specialization for N=2 2D-Array
template<typename T,size_t N1,size_t N2>
struct write_stag<T[N1][N2]>
{
	/*! \brieg write the staggered grid
	 *
	 * \tparam p_val property we are going to write
	 * \tparam sg staggered grid type
	 * \tparam v_g vector of grids
	 *
	 * \param st_g staggered grid
	 * \param v_g vector of grids
	 * \param i local grid of the staggered grid we are writing
	 *
	 */
	template<unsigned int p_val, typename sg, typename v_g> static inline void write(sg & st_g, v_g & vg,size_t lg)
	{
		for (size_t i = 0 ; i < N1 ; i++)
		{
			for (size_t j = 0 ; j < N2 ; j++)
			{
				// Add a grid;
				vg.add();
				size_t k = vg.size() - 1;

				// Set dimensions and memory
				vg.get(k).resize(st_g.get_loc_grid(lg).getGrid().getSize());

				// copy
				auto & g_src = st_g.get_loc_grid(lg);
				auto & g_dst = vg.get(k);
				auto it = vg.get(k).getIterator();

				while(it.isNext())
				{
					g_dst.template get<0>(it.get()) = g_src.template get<p_val>(it.get())[i][j];

					++it;
				}
			}
		}
	}
};

///////////////////// Staggered default positioning ////////////////////////

/*! \brief this class is a functor for "for_each" algorithm
 *
 * For each element of the boost::vector the operator() is called.
 * Is mainly used to produce a default position vector for each
 * property
 *
 * \tparam dim dimensionality
 * \tparam v boost::fusion::vector of properties
 * \tparam has_posMask case when v has a position mask
 *
 */

template<unsigned int dim, typename v, bool has_pM = has_posMask<v>::value>
class stag_set_position
{
	openfpm::vector<comb<dim>> (& pos_prp)[boost::fusion::result_of::size<v>::type::value];

public:

	stag_set_position( openfpm::vector<comb<dim>> (& pos_prp)[boost::fusion::result_of::size<v>::type::value])
	:pos_prp(pos_prp)
	{}

	//! It call the copy function for each property
	template<typename T>
	void operator()(T& t) const
	{
		// This is the type of the object we have to copy
		typedef typename boost::mpl::at<v,typename boost::mpl::int_<T::value>>::type prop;

		bool val = prop::stag_pos_mask[T::value];

		if (val == false)
			return;

		// Dimension of the object
		size_t dim_prp = extends<prop>::dim();

		// It is a scalar
		if (dim_prp == 0)
		{
			comb<dim> c;
			c.zero();

			// It stay in the center
			pos_prp[T::value].add(c);
		}
		else if (dim_prp == 1)
		{
			// It stay on the object of dimension dim-1 (Negative part)
			for (size_t i = 0 ; i < dim ; i++)
			{
				comb<dim> c;
				c.zero();
				c.value(i) = -1;

				pos_prp[T::value].add(c);
			}
		}
		else if (dim_prp == 2)
		{
			// Create an hypercube object
			HyperCube<dim> hyp;

			// Diagonal part live in
			for (size_t i = 0 ; i < dim ; i++)
			{
				comb<dim> c1 = pos_prp[T::value-1].get(i);
				for (size_t j = 0 ; j < dim ; j++)
				{
					comb<dim> c2;
					c2.zero();
					c2.value(i) = 1;

					comb<dim> c_res = (c1 + c2) & 0x1;

					pos_prp[T::value].add(c_res);
				}
			}
		}
		else if (dim_prp > 2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << " Tensor of rank bigger than 2 are not supported";
		}
	}
};

///////////////////// Staggered default positioning ////////////////////////

/*! \brief this class is a functor for "for_each" algorithm
 *
 * For each element of the boost::vector the operator() is called.
 * Is mainly used to produce a default position vector for each
 * property
 *
 * \tparam vector of properties
 *
 */

template<unsigned int dim, typename v>
class stag_set_position<dim,v,false>
{
private:
	openfpm::vector<comb<dim>> (& pos_prp)[boost::fusion::result_of::size<v>::type::value];


public:
	stag_set_position( openfpm::vector<comb<dim>> (& pos_prp)[boost::fusion::result_of::size<v>::type::value])
	:pos_prp(pos_prp)
	{}

	//! It call the copy function for each property
	template<typename T>
	void operator()(T& t) const
	{
		// This is the type of the object we have to copy
		typedef typename boost::mpl::at<v,typename boost::mpl::int_<T::value>>::type prop;

		// Dimension of the object
		size_t dim_prp = extends<prop>::dim();

		// It is a scalar
		if (dim_prp == 0)
		{
			comb<dim> c;
			c.zero();

			// It stay in the center
			pos_prp[T::value].add(c);
		}
		else if (dim_prp == 1)
		{
			// It stay on the object of dimension dim-1 (Negative part)
			for (size_t i = 0 ; i < dim ; i++)
			{
				comb<dim> c;
				c.zero();
				c.getComb()[i] = -1;

				pos_prp[T::value].add(c);
			}
		}
		else if (dim_prp == 2)
		{
			// Diagonal part live in
			for (size_t i = 0 ; i < dim ; i++)
			{
				comb<dim> c1 = pos_prp[T::value-1].get(i);
				for (size_t j = 0 ; j < dim ; j++)
				{
					comb<dim> c2;
					c2.zero();
					c2.getComb()[j] = 1;

					comb<dim> c_res = (c2 + c1).flip();

					pos_prp[T::value].add(c_res);
				}
			}
		}
		else if (dim_prp > 2)
		{
			std::cerr << __FILE__ << ":" << __LINE__ << " Tensor of rank bigger than 2 are not supported";
		}
	}
};

/*! \brief It create separated grid for each properties to write them into a file
 *
 * \tparam dim dimensionality of the grids
 * \tparam obj type object to print, must be in OpenFPM format
 *
 */
template<unsigned int dim, typename st_grid, typename St>
class stag_create_and_add_grid
{

	size_t p_id;

	// staggered grid to write
	st_grid & st_g;

public:

	/*! \brief Constructor
	 *
	 * \param st_g staggered grid
	 * \param p_id process id
	 *
	 */
	stag_create_and_add_grid(st_grid & st_g, size_t p_id)
	:p_id(p_id),st_g(st_g)
	{}

	template<unsigned int p_val> void out_normal()
	{
		// property type
		typedef typename boost::mpl::at< typename st_grid::value_type::type , typename boost::mpl::int_<p_val> >::type ele;

		// create an openfpm format object from the property type
		typedef object<typename boost::fusion::vector<ele>> d_object;

		VTKWriter<boost::mpl::pair<grid_cpu<dim, d_object >,St>,VECTOR_GRIDS> vtk_w;

		// Create a vector of grids

		openfpm::vector< grid_cpu<dim, d_object > > vg(st_g.getN_loc_grid());

		// for each domain grid
		for (size_t i = 0 ; i < vg.size() ; i++)
		{
			// Set dimansions and memory
			vg.get(i).resize(st_g.get_loc_grid(i).getGrid().getSize());

			auto & g_src = st_g.get_loc_grid(i);
			auto & g_dst = vg.get(i);

			auto it = vg.get(i).getIterator();

			while(it.isNext())
			{
				object_si_d< decltype(g_src.get_o(it.get())),decltype(g_dst.get_o(it.get())) ,OBJ_ENCAP,p_val>(g_src.get_o(it.get()),g_dst.get_o(it.get()));

				++it;
			}

			Point<dim,St> offset = st_g.getOffset(i);
			Point<dim,St> spacing = st_g.getSpacing();
			Box<dim,size_t> dom = st_g.getDomain(i);

			vtk_w.add(g_dst,offset,spacing,dom);
		}

		vtk_w.write("vtk_grids_st_" + std::to_string(p_id) + "_" + std::to_string(p_val) + ".vtk");
	}

	template<unsigned int p_val> void out_staggered()
	{
		// property type
		typedef typename boost::mpl::at< typename st_grid::value_type::type , typename boost::mpl::int_<p_val> >::type ele;

		// Eliminate the extends
		typedef typename std::remove_all_extents<ele>::type r_ele;

		// create an openfpm format object from the property type
		typedef object<typename boost::fusion::vector<r_ele>> d_object;

		VTKWriter<boost::mpl::pair<grid_cpu<dim, d_object >,St>,VECTOR_ST_GRIDS> vtk_w;

		// Create a vector of grids
		openfpm::vector< grid_cpu<dim, d_object > > vg;
		vg.reserve(st_g.getN_loc_grid() * extends<ele>::mul());

		size_t k = 0;

		// for each domain grid
		for (size_t i = 0 ; i < st_g.getN_loc_grid() ; i++)
		{
			write_stag<ele>::template write<p_val, st_grid,openfpm::vector< grid_cpu<dim, d_object > > >(st_g,vg,i);

			// for each component
			for ( ; k < vg.size() ; k++)
			{
				Point<dim,St> offset = st_g.getOffset(i);
				Point<dim,St> spacing = st_g.getSpacing();
				Box<dim,size_t> dom = st_g.getDomain(i);

				vtk_w.add(i,vg.get(k),offset,spacing,dom,st_g.c_prp[p_val].get(k));
			}

			k = vg.size();
		}

		vtk_write<typename st_grid::value_type,VTKWriter<boost::mpl::pair<grid_cpu<dim, d_object >,St>,VECTOR_ST_GRIDS>> v(vtk_w,"vtk_grids_st_" + std::to_string(p_id),p_val);
	}

	//! It call the copy function for each property
	template<typename T>
	void operator()(T& t)
	{
		if (st_g.is_staggered_prop(T::value) == false)
			out_normal<T::value>();
		else
			out_staggered<T::value>();
	}
};

#endif /* SRC_GRID_STAGGERED_DIST_GRID_UTIL_HPP_ */
