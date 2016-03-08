/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef CASADI_COMPILER_INTERNAL_HPP
#define CASADI_COMPILER_INTERNAL_HPP

#include "compiler.hpp"
#include "function_internal.hpp"
#include "plugin_interface.hpp"
#include "../casadi_file.hpp"


/// \cond INTERNAL
namespace casadi {

/** \brief NLP solver storage class

  @copydoc Compiler_doc
  \author Joel Andersson
  \date 2010-2013
*/
  class CASADI_EXPORT
  CompilerInternal : public SharedObjectNode,
                     public PluginInterface<CompilerInternal> {

  public:
    /// Constructor
    explicit CompilerInternal(const std::string& name);

    /// Destructor
    virtual ~CompilerInternal();

    /** \brief Print */
    virtual void print(std::ostream &stream) const;

    /** \brief Print representation */
    virtual void repr(std::ostream &stream) const;

    // Creator function for internal class
    typedef CompilerInternal* (*Creator)(const std::string& name);

    /** \brief Construct
        Prepares the function for evaluation
     */
    void construct(const Dict& opts);

    ///@{
    /** \brief Options */
    static Options options_;
    virtual const Options& get_options() const { return options_;}
    ///@}

    /** \brief Initialize */
    virtual void init(const Dict& opts);

    // No static functions exposed
    struct Exposed{ };

    /// Collection of solvers
    static std::map<std::string, Plugin> solvers_;

    /// Infix
    static const std::string infix_;

    /// Short name
    static std::string shortname() { return "compiler";}

    /// Queery plugin name
    virtual const char* plugin_name() const { return "none";}

    /// Get a function pointer for numerical evaluation
    virtual void* getFunction(const std::string& symname) { return 0;}

    /// Get meta information, if any
    void get_meta(std::vector<std::string>& lines, int& offset) const;

    protected:
    /// C filename
    std::string name_;

    /// Meta information
    ParsedFile meta_;
  };

} // namespace casadi
/// \endcond
#endif // CASADI_COMPILER_INTERNAL_HPP
