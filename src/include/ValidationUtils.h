#pragma once

#include "LNLibDefinitions.h"
#include <vector>

namespace LNLib
{
	class XYZW;
	class LNLIB_EXPORT ValidationUtils
	{
	public:

		static bool IsInRange(double input, double min, double max);

		static bool IsValidBezier(unsigned int degree, unsigned int controlPointsCount);

		static bool IsValidBspline(unsigned int degree, unsigned int knotVectorCount, unsigned int controlPointsCount);

		static bool IsValidNurbs(unsigned int degree, unsigned int knotVectorCount, unsigned int controlPointsCount, unsigned int weightsCount);

		static bool IsValidDegreeReduction(unsigned int degree);

		/// <summary>
		/// The NURBS Book 2nd Edition Page185.
		/// TOL = dWmin / (1+abs(Pmax)).
		/// </summary>
		static double ComputeCurveModifyTolerance(const std::vector<XYZW>& controlPoints);

		/// <summary>
		/// The NURBS Book 2nd Edition Page221.
		/// Implements Bezier degree reduction and computation of the maximum error.
		/// </summary>
		static double ComputeMaxErrorOfBezierReduction(unsigned int degree, const std::vector<XYZW>& current, const std::vector<XYZW>& reduction);
	};
}

