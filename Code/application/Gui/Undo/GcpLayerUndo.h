/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#ifndef GCPLAYERUNDO_H
#define GCPLAYERUNDO_H

#include "ColorType.h"
#include "LayerUndo.h"
#include "TypesFile.h"
#include "UndoAction.h"

class GcpLayer;

class SetGcpColor : public UndoAction
{
public:
   SetGcpColor(GcpLayer* pLayer, const ColorType& oldColor, const ColorType& newColor);

   void executeUndo();
   void executeRedo();

private:
   SetGcpColor(const SetGcpColor& rhs);
   SetGcpColor& operator=(const SetGcpColor& rhs);
   ColorType mOldColor;
   ColorType mNewColor;
};


class SetGcpSymbol : public UndoAction
{
public:
   SetGcpSymbol(GcpLayer* pLayer, GcpSymbol oldSymbol, GcpSymbol newSymbol);

   void executeUndo();
   void executeRedo();

private:
   SetGcpSymbol(const SetGcpSymbol& rhs);
   SetGcpSymbol& operator=(const SetGcpSymbol& rhs);
   GcpSymbol mOldSymbol;
   GcpSymbol mNewSymbol;
};


class SetGcpSymbolSize : public UndoAction
{
public:
   SetGcpSymbolSize(GcpLayer* pLayer, int oldSize, int newSize);

   void executeUndo();
   void executeRedo();

private:
   SetGcpSymbolSize(const SetGcpSymbolSize& rhs);
   SetGcpSymbolSize& operator=(const SetGcpSymbolSize& rhs);
   int mOldSize;
   int mNewSize;
};


class GcpLayerMemento : public LayerMemento
{
public:
   GcpLayerMemento(GcpLayer* pLayer);
   void toLayer(Layer* pLayer) const;

private:
   GcpLayerMemento(const GcpLayerMemento& rhs);
   GcpLayerMemento& operator=(const GcpLayerMemento& rhs);
   ColorType mColor;
   GcpSymbol mSymbol;
   int mSymbolSize;
};

#endif
