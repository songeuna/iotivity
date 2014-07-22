//******************************************************************
//
// Copyright 2014 Intel Corporation All Rights Reserved.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// ============================================================================
// Includes
// ============================================================================
#include "LiteConnection.h"

// ============================================================================
// Namespace
// ============================================================================
namespace remoting {

  // ============================================================================
  // Constructor/Destructor
  // ============================================================================
    //---------------------------------------------------------------------------
    // Constructor
    //---------------------------------------------------------------------------
  LiteConnection::LiteConnection(int socket) : socket_(socket)
  {

  }

  //---------------------------------------------------------------------------
  // Destructor
  //---------------------------------------------------------------------------
  LiteConnection::~LiteConnection()
  {
  }

}
