#ifndef GRID_DIST_KEY_DX_HPP
#define GRID_DIST_KEY_DX_HPP

/*! \brief Grid key for a distributed grid
 *
 * Grid key for a distributed grid
 *
 */

template<unsigned int dim>
class grid_dist_key_dx
{
	//! grid list counter

	size_t g_c;

	//! Local grid iterator

	grid_key_dx<dim> key;

public:

	/*! \brief Get the local grid
	 *
	 * \return the id of the local grid
	 *
	 */
	size_t getSub()
	{
		return g_c;
	}

	/*! \brief Get the key
	 *
	 * \return the local key
	 *
	 */
	grid_key_dx<dim> getKey()
	{
		return key;
	}

	grid_dist_key_dx(int g_c, grid_key_dx<dim> key)
	:g_c(g_c),key(key)
	{
	}
};

#endif