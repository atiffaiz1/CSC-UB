# Copyright (c) 2016, Adam Rall
# All rights reserved.
#
# This file is a part of coex <http://github.com/adamrall/coex>.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

"""Find the wetting properties of a direct or expanded ensemble
grand canonical simulation.
"""

import numpy as np


def get_cos_theta(s, d):
    """Calculate the cosine of the contact angle.

    Args:
        s: A float (or numpy array): the spreading coefficient.
        d: A float (or numpy array): the drying coefficient.

    Returns:
        The cosine of the contact angle as a float or numpy array.
    """
    return -(s - d) / (s + d)


def get_drying_coefficient(distribution):
    """Calculate the drying coefficient.

    Args:
        distribution: An OrderParameterDistribution from a direct (GC)
            drying simulation.

    Returns:
        The dimensionless drying coefficient (beta*d*A).
    """
    potential = -distribution.log_probabilities
    valley = np.amin(potential)
    split = int(0.5 * len(potential))
    plateau = np.mean(potential[:split])

    return valley - plateau


def get_expanded_ensemble_coefficients(valley, plateau, index, reference):
    """Calculate the change in spreading/drying coefficient for a pair of
    simulations.

    Args:
        valley: An OrderParameterDistribution from the valley region.
        plateau: An OrderParameterDistribution from the plateau
            region.
        index: The reference subensemble number.
        reference: The reference spreading/drying coefficient.

    Returns:
        A numpy array with the spreading/drying coefficient of each
        subensemble.
    """
    return reference - (valley - valley[index]) + (plateau - plateau[index])


def get_spreading_coefficient(distribution):
    """Calculate the spreading coefficient.

    Args:
        distribution: An OrderParameterDistribution from a direct (GC)
            spreading simulation.

    Returns:
        The dimensionless spreading coefficient (beta*s*A).
    """
    potential = -distribution.log_probabilities
    valley = np.amin(potential)
    split = int(0.5 * len(potential))
    plateau = np.mean(potential[split:])

    return valley - plateau


def get_tension(s, d):
    """Calculate the interfacial tension.

    Args:
        s: A float (or numpy array): the spreading coefficient.
        d: A float (or numpy array): the drying coefficient.

    Returns:
        The interfacial tension in the appropriate units.
    """
    return -0.5 * (s + d)
